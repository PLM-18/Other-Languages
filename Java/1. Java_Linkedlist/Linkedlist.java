public class Linkedlist<T> {
    Node<T> head;
    int size;
    public Linkedlist() {
        head = null;
        size = 0;
    }

    public Linkedlist(Linkedlist<T> list) {
        this.head = list.head;
        this.size = list.size;
    }

    public void insert(T data){
        if(head == null){
            head = new Node<T>(data);
        } else {
            Node<T> temp = head;
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = new Node<T>(data);
        }
    }

    public void remove(T data){
        if(head == null){
            return;
        }
        if(head.data.equals(data)){
            head = head.next;
            return;
        }
        Node<T> temp = head;
        while(temp.next != null){
            if(temp.next.data.equals(data)){
                temp.next = temp.next.next;
                return;
            }
            temp = temp.next;
        }
    }

    public int size(){
        return size;
    }

    @SuppressWarnings("unchecked")
    public Linkedlist<T> sort(){
        Linkedlist<T> sorted = new Linkedlist<T>(this);
        Node<T> temp = sorted.head;
        while(temp != null){
            Node<T> min = temp;
            Node<T> r = temp.next;
            while(r != null){
                if(((Comparable<T>)r.data).compareTo(min.data) < 0){
                    min = r;
                }
                r = r.next;
            }
            T x = temp.data;
            temp.data = min.data;
            min.data = x;
            temp = temp.next;
        }
        return sorted;
    }

    public void print(){
        Node<T> temp = head;
        while(temp != null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}
