class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
      ListNode* dummy = new ListNode();
      ListNode* temp = new ListNode();

      int val1 = 0 ; 
      while( l1 != NULL || l2 != NULL || val){
        int sum  = 0;
        if(l1 != NULL){
          sum += l1->val1;
          l1 = l1 -> next;
        }

        if(l2 != NULL){
          sum += val1;
          val1 = sum / 10;
          ListNode* node = new ListNode();
          temp -> next = node;
          temp = temp -> next;
        }
        return dummy -> next;
      }
    }
}
