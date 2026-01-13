class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        while (head != nullptr) { 
            ListNode* next = head->next; 
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
};

//------------------------------------------------------------------nullptr

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if ( head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* newhead = reverseList( head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newhead;

        
    }
};
