public class Linkedlist{
	Node head;
	int size;

	public Linkedlist(){
		head = null;
		size = 0;
	}
	
	public int size(){
		return size;
	}

	public void insert(int data){
		if(contains(data)) return;
		Node newNode = new Node(data);
		if(head == null){
			head = newNode;
		}else{
			Node cur = head;
			while(cur.next != null){
				cur = cur.next;
			}
			cur.next = newNode;
		}
		size++;
	}

	public void remove(int data){

	}

	public int get(int index){

	}

	public int indexOf(int data){
		Node cur = head;
		int count = 0;
		while(cur != null){
			if(cur.data == data) return count;
			cur = cur.next;
			count++;
		}
		return -1;
	}

	public boolean contains(int data){
		Node cur = head;
		while(cur != null){
			if(cur.data == data) return true;
			cur = cur.next;
		}
		return false;
	}

	public void removeIndex(int index){
	
	}

	public void print(){
		Node cur = head;
		while(cur != null){
			System.out.print(cur.data+"->");
			cur = cur.next;
		}
		System.out.println("null");
	}

}
