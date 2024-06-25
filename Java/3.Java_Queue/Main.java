import Queues.Queue;

public class Main
{
    public static void main(String[] args)
    {
        Queue newQueue = new Queue();
        newQueue.Engueue(23);
        newQueue.Engueue(45);
        /* newQueue.Engueue(31);
        newQueue.Engueue(10); */
        newQueue.Dequeue();
        newQueue.Dequeue();
        System.out.println(newQueue.length());
        newQueue.print();
    }
}