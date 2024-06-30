public class BST {
    TreeNode root;

    public BST() {
        root = null;
    }

    public BST(TreeNode root) {
        this.root = root;
    }

    public void insert(int data) {
        if (root == null) {
            root = new TreeNode(data);
            return;
        }
        TreeNode node = root;
        while (true) {
            if (node.data > data) {
                if (node.left == null) {
                    node.left = new TreeNode(data);
                    break;
                }
                node = node.left;
            } else {
                if (node.right == null) {
                    node.right = new TreeNode(data);
                    break;
                }
                node = node.right;
            }
        }
    }

    public void remove(int data) {
        if(!contains(data)) return;
        root = removeHelper(root, data);
    }

    public TreeNode removeHelper(TreeNode node, int data) {
        if (node == null) {
            return null;
        }
        if (node.data == data) {
            if (node.left == null && node.right == null) {
                return null;
            }
            if (node.left == null) {
                return node.right;
            }
            if (node.right == null) {
                return node.left;
            }
            TreeNode minNode = findMin(node.right);
            node.data = minNode.data;
            node.right = removeHelper(node.right, minNode.data);
            return node;
        }
        if (node.data > data) {
            node.left = removeHelper(node.left, data);
        } else {
            node.right = removeHelper(node.right, data);
        }
        return node;
    }

    public String searchpath(int data) {
        if(root == null) return "Empty tree";
        TreeNode node = root;
        StringBuilder sb = new StringBuilder();
        while(node != null){
            sb.append(node.data).append("->");
            if(node.data == data) break;
            if(node.data < data){
                node = node.right;
            }else node = node.left;
        }
        sb.append("null");
        return sb.toString();
    }

    public int getHeight() {
        TreeNode node = root;
        return getHeightHelper(node);
    }

    public int getHeightHelper(TreeNode node) {
        if (node == null) {
            return 0;
        } else {
            int leftHeight = getHeightHelper(node.left);
            int rightHeight = getHeightHelper(node.right);
            return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
        }
    }

    //tester
    public String isEmpty(){
        if(root == null) return "Empty tree";
        return "Not empty";
    }

    public int getNumLeaves() {
        return countLeaves(root);
    }

    public int countLeaves(TreeNode node) {
        if (node == null) {
            return 0;
        }
        if (node.left == null && node.right == null) {
            return 1;
        } else {
            return countLeaves(node.left) + countLeaves(node.right);
        }
    }

    public BST extractBiggestSuperficiallyBalancedSubTree() {
        if(root == null) return new BST();
        return extractTree(root);
    }

    public BST extractTree(TreeNode node) {
        if (node == null) {
            return new BST();
        }
        if (isSuperficiallyBalanced(node)) {
            return new BST(node);
        }
        BST left = extractTree(node.left);
        BST right = extractTree(node.right);
        return (left.getHeight() > right.getHeight()) ? left : right;
    }

    public boolean isSuperficiallyBalanced(TreeNode node) {
        if (node == null) {
            return true;
        }
        int leftHeight = getHeightHelper(node.left);
        int rightHeight = getHeightHelper(node.right);
        return Math.abs(leftHeight - rightHeight) <= 1;
    }

    public TreeNode getNode(int data) {
        return searchNode(root, data);
    }

    public boolean isSuperficiallyBalanced() {
        return isSuperficiallyBalanced(root);
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
