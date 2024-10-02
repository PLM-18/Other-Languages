public class Main{
    public static void main(String[] args) {
        CompositeLock lock = new CompositeLock();
        lock.lock();
        System.out.println("Locked");
    }
}