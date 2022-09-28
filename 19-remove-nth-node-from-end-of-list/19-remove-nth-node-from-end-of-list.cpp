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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* secd = head;
        
        if(temp == NULL && temp->next == NULL) return NULL;
            
        while(n--) {
            temp = temp->next;
        }
        
        if(temp==NULL)
            return head->next;
        
        while(temp->next!=NULL) {
            temp = temp->next;
            secd = secd->next;
        }
        
        secd->next = secd->next->next;
        return head;
    }
};