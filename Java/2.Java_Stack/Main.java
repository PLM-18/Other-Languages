import Stack.Stack;

public class Main 
{
    public static void main(String[] args)
    {
        Stack newStack = new Stack();
        newStack.push(23);
        newStack.push(11);
        newStack.push(50);
        newStack.print();
        System.out.println(newStack.pop());
        newStack.print();
    }
}
