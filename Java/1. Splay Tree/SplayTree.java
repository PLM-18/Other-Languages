public class SplayTree {
    public Node root;

    @Override
    public String toString() {
        return (root == null ? "Empty Tree" : toString(root, "", true));
    }

    public String toString(Node node, String prefix, boolean end) {
        String res = "";
        if (node.right != null) {
            res += toString(node.right, prefix + (end ? "│   " : "    "), false);
        }
        res += prefix + (end ? "└── " : "┌── ") + node.toString() + "\n";
        if (node.left != null) {
            res += toString(node.left, prefix + (end ? "    " : "│   "), true);
        }
        return res;
    }

    public String toStringOneLine() {
        return (root == null ? "Empty Tree" : "{" + toStringOneLine(root) + "}");
    }

    public String toStringOneLine(Node node) {
        return node.toString()
                + (node.left == null ? "{}" : "{" + toStringOneLine(node.left) + "}")
                + (node.right == null ? "{}" : "{" + toStringOneLine(node.right) + "}");
    }

    public SplayTree() {
        root = null;
    }

    public SplayTree(String input) {
        
    }

    public Node access(int studentNumber) {
       return getStudentNumber(root, studentNumber);
    }
	
	//helper function for studentnumber fetch
	private Node getStudentNumber(Node node, int studentNumber){
		if(node == null) return null;
		if(node.studentnumber ==  studentNumber) return node;
		if(node.studentnumber > studentNumber) return getStudentNumber(node.left, studentNumber);
		return getStudentNumber(node.right, studentNumber);
	}

    public Node access(int studentNumber, Integer mark) {
       
    }

    public Node remove(int studentNumber) {
       
    }

    public String sortByStudentNumber(){
        
    }

    public String sortByMark() {
      
    }
}
