public class Main {
    
    public static void main(String[] args) {
        ListNode l1 = new ListNode(9, new ListNode(9, new ListNode(9)));
        ListNode l2 = new ListNode(5, new ListNode(5));
        Solution solution = new Solution();
        ListNode result = solution.addTwoNumbers(l1, l2);
        System.out.println("["+l1.toString()+"] + ["+l2.toString()+"] = ["+result.toString()+"]");
    }
}
