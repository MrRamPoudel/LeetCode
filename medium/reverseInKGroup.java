class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode Dummy = new ListNode(0, head);
        ListNode GPrev = Dummy;
        while(true) {
            ListNode kthNode = getKthNode(GPrev, k);
            if(kthNode == null) {
                break;
            }
            ListNode GNext = kthNode.next;

            //start reversing
            ListNode prev = kthNode.next;
            ListNode curr = GPrev.next;
            while(curr != GNext) {
                ListNode temp  = curr.next;
                curr.next = prev;
                prev = curr;
                curr = temp;
            }

            //Rearrage the nodes here
            ListNode temp = GPrev.next;
            GPrev.next = kthNode;
            GPrev = temp;
        }
        return Dummy.next;
    }
    public static ListNode getKthNode(ListNode start, int k) {
        while(start != null  && k > 0) {
            start = start.next;
            --k;
        }
        return start;
    }
}