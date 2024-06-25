public class Main {
	public static void main(String[] args){
        Linkedlist<Integer> list = new Linkedlist<Integer>();
        list.insert(5);
        list.insert(3);
        list.insert(7);
        list.insert(1);
        list.insert(9);
        list.insert(2);
        list.insert(6);
        list.insert(4);
        list.insert(8);
        list.print();
        Linkedlist<Integer> sorted = list.sort();
        sorted.print();
    }
}