import java.util.Random;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;
import java.util.concurrent.atomic.AtomicStampedReference;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

// Define the Backoff class
class Backoff {
    private final int minDelay, maxDelay;
    private int limit;
    private final Random random;

    public Backoff(int minDelay, int maxDelay) {
        this.minDelay = minDelay;
        this.maxDelay = maxDelay;
        this.limit = minDelay;
        this.random = new Random();
    }

    public void backoff() throws InterruptedException {
        int delay = random.nextInt(limit);
        if (limit < maxDelay) {
            limit = Math.min(maxDelay, 2 * limit);
        }
        Thread.sleep(delay);
    }
}

public class CompositeLock implements Lock{
    private static final int SIZE = 100;
    private static final int MIN_BACKOFF = 100;
    private static final int MAX_BACKOFF = 1000;
    AtomicStampedReference<Qnode> tail;
    Qnode[] waiting;
    Random random;
    ThreadLocal<Qnode> myNode = new ThreadLocal<Qnode>(){
        protected Qnode initialValue(){
            return new Qnode();
        }
    };

    public CompositeLock(){
        tail = new AtomicStampedReference<>(new Qnode(), 0);
        waiting = new Qnode[SIZE];
        random = new Random();
        for(int i = 0; i < SIZE; i++){
            waiting[i] = new Qnode();
        }
    }

    public void unlock(){
        Qnode acqNode = myNode.get();
        acqNode.state.set(State.RELEASED);
        myNode.set(new Qnode());
    }

    public boolean tryLock(long time, TimeUnit unit) throws InterruptedException{
        long patience = TimeUnit.MILLISECONDS.convert(time, unit);
        long startTime = System.currentTimeMillis();
        Backoff backoff = new Backoff(MIN_BACKOFF, MAX_BACKOFF);
        try{
            Qnode node = acquireNode(backoff, startTime, patience);
            Qnode prev = spliceNode(node, startTime, patience);
            waitForPredecessor(prev, node, startTime, patience);
            return true;
        }catch(TimeoutException e){
            return false;
        }
    }

    private Qnode acquireNode(Backoff backoff, long startTime, long patience) throws TimeoutException, InterruptedException{
        Qnode node = waiting[random.nextInt(SIZE)];
        Qnode currtail;
        State state = node.state.get();
        while(true){
            if(node.state.compareAndSet(State.FREE, State.WAITING)){
                return node;
            }
            int[] currStamp = {0};
            currtail = tail.get(currStamp);
            if(state == State.ABORTED || state == State.RELEASED){
                if(node == currtail){
                    Qnode myprev = new Qnode();
                    if(state == State.ABORTED){
                        myprev = node.prev;
                    }
                    if(tail.compareAndSet(currtail, myprev, currStamp[0], currStamp[0] + 1)){
                        node.state.set(State.WAITING);
                        return node;
                    }
                }
            }
            backoff.backoff();
            if(timeout(patience, startTime)){
                throw new TimeoutException();
            }
        }
    }

    private boolean timeout(long patience, long startTime) {
        return System.currentTimeMillis() - startTime > patience;
    }

    private Qnode spliceNode(Qnode node, long startTime, long patience) throws TimeoutException, InterruptedException{
        Qnode currtail;
        int[] currStamp = {0};
        do{
            currtail = tail.get(currStamp);
            if(timeout(startTime, patience)){
                node.state.set(State.FREE);
                throw new TimeoutException();
            }
        }while(!tail.compareAndSet(currtail, node, currStamp[0], currStamp[0] + 1));
        return currtail;
    }

    private void waitForPredecessor(Qnode prev, Qnode node, long startTime, long patience) throws TimeoutException, InterruptedException{
        if(prev == null){
            myNode.set(node);
            return;
        }

        State state = prev.state.get();
        while(state != State.RELEASED){
            if(state == State.ABORTED){
                Qnode temp = prev;
                prev = prev.prev;
                temp.state.set(State.FREE);
            }
            if(timeout(patience, startTime)){
                node.prev = prev;
                node.state.set(State.FREE);
                throw new TimeoutException();
            }
            state = prev.state.get();
        }
        prev.state.set(State.FREE);
        myNode.set(node);
    }

    @Override
    public void lock() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'lock'");
    }

    @Override
    public void lockInterruptibly() throws InterruptedException {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'lockInterruptibly'");
    }

    @Override
    public Condition newCondition() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'newCondition'");
    }

    @Override
    public boolean tryLock() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'tryLock'");
    }
}

