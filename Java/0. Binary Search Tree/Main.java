public class Main {
    
    public static void main(String[] args) {
        BST tree = new BST();
        tree.insert(2);
        tree.insert(45);
        tree.insert(7);
        tree.insert(26);
        tree.insert(17);
        tree.insert(18);
        tree.insert(28);
        System.out.println(tree.searchpath(26));
        System.out.println(tree.isEmpty());
        System.out.println(tree.toString());
    }
}
