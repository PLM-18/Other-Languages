import java.util.concurrent.atomic.AtomicReference;

enum State {
    FREE, WAITING, RELEASED, ABORTED    
}

public class Qnode {
    AtomicReference<State> state;
    Qnode prev;

    public Qnode() {
        state = new AtomicReference<>(State.FREE);
    }
}
