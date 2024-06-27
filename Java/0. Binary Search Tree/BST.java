public class BST {
    TreeNode root;

    public BST() {
        root = null;
    }

    public void insert(int data) {
        if(contains(data)) return;
        TreeNode newNode = new TreeNode(data);
        TreeNode node = root;
        while(node != null){
            if(node.data < data){
                node = node.right;
            }else node = node.left;
        }
        node = newNode;
    }

    public void remove(int data) {
        if(!contains(data)) return;
        TreeNode cur = root;
        TreeNode prev = null;
        while(cur.data != data){
            prev = cur;
            if(cur.data < data){
                cur = cur.right;
            }else cur = cur.left;
        }
        
        if(prev.left == cur){
            prev.left = findMin(cur.right);
            prev.left.left = cur.left;
            prev.left.right = cur.right;
        }else{
            prev.right = findMin(cur.right);
            prev.right.left = cur.left;
            prev.right.right = cur.right;
        }
    }

    public String searchpath(TreeNode node) {
        return "";
    }

    public int getHeight() {
        return 0;
    }

    public int getNumLeaves() {
        return 0;
    }

    public BST extractBiggestSuperficiallyBalancedSubTree() {
        return null;
    }

    private void includeNodes(BST newTree, TreeNode node) {

    }

    public TreeNode getNode(int data) {
        return searchNode(root, data);
    }

    public boolean isSuperficiallyBalanced() {
        return false;
    }

    public TreeNode findMax() {
        TreeNode node = root;
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }

    public TreeNode findMin(TreeNode node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }


    public boolean contains(int data) {
        return (searchNode(root, data) != null);
    }

    // helper SearchNode
    public TreeNode searchNode(TreeNode node, int data) {
        if (node == null)
            return null;
        if (node.data == data)
            return node;
        return (node.data > data) ? searchNode(node.left, data) : searchNode(node.right, data);
    }

    private StringBuilder toString(TreeNode node, StringBuilder prefix, boolean isTail, StringBuilder sb) {
        if (node.right != null) {
            toString(node.right, new StringBuilder().append(prefix).append(isTail ? "│   " : "    "), false, sb);
        }
        sb.append(prefix).append(isTail ? "└── " : "┌── ").append(node.data).append("\n");
        if (node.left != null) {
            toString(node.left, new StringBuilder().append(prefix).append(isTail ? "    " : "│   "), true, sb);
        }
        return sb;
    }

    @Override
    public String toString() {
        return root == null ? "Empty tree" : toString(root, new StringBuilder(), true, new StringBuilder()).toString();
    }

}
