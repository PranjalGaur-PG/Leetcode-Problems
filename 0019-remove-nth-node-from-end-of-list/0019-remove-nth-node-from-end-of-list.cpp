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
        int x = n;
        if(n==0 || head == NULL) return head;
        
        ListNode ans(-1);
        ans.next = head;
        
        ListNode* temp = &ans, *temp2 = &ans;
        
        while(x--) temp = temp->next;
        
        while(temp->next) {
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        temp2->next = temp2->next->next;
        
        return ans.next;
    }
};