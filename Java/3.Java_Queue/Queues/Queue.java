package Queues;
import Nodes.Node;

public class Queue 
{
    Node front;
    Node rear;

    public Queue()
    {
        front = null;
        rear = null;
    }

    public int length()
    {
        int Count = 0;
        Node cur = front;
        while(cur != null)
        {
            cur = cur.next;
            Count++;
        }
        return Count;
    }

    public void Engueue(int val)
    {
        Node newNode = new Node(val);
        if(rear == null)
        {
            front = newNode;
            rear = newNode;
            rear.next = null;
        }
        else
        {
            rear.next = newNode;
            rear = newNode;
            rear.next = null;
        }

    }

    public int Dequeue()
    {
        if(rear == null)
        {
            return -1;
        }

        int num = rear.data;

        return num;

    }

    public void print()
    {
        Node cur = front;
        while(cur != rear)
        {
            System.out.print(cur.data + "->");
            cur = cur.next;
        }
        System.out.println(rear.data+"-> NULL");
    }
}
