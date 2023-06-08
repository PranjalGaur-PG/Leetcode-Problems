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
    ListNode* rec(ListNode* head, ListNode* prev) {
        if(head->next == NULL) {
            head->next = prev;
            return head; 
        }
        
        ListNode* nxt = rec(head->next, head);
        head->next = prev;
        
        return nxt;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* root = rec(head, NULL);
        return root;
    }
};