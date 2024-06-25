package Stack;
import Nodes.Node;

public class Stack 
{
    Node top;
    public Stack()
    {
        top = null;
    }

    public void push(int val)
    {
        Node newNode = new Node(val);
        newNode.next = top;
        top = newNode;
    }

    public int pop()
    {
        if(top == null)
        {
            return 0;
        }

        Node cur = top;
        top = top.next;
        return cur.data;
    }

    public void print()
    {
        Node cur = top;
        while(cur != null)
        {
            System.out.print(cur.data +"->");
            cur = cur.next;
        }
        System.out.println("NULL");
    }
}
