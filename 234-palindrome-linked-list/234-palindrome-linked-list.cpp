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
    bool isPalindrome(ListNode* head) {
//         if(head->next == NULL) return false;
        
//         ListNode* slow = head, *fast=head;
//         ListNode *pre=NULL, *cur=head, *nxt=NULL;
//         while(fast!=NULL && fast->next!=NULL) {
//             pre = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         pre->next = NULL;
        
//         while(slow!=NULL) {
            
//         }
        vector<int>v;
        ListNode *temp=head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int s=0,e=v.size()-1;
        while(s<e){
            if(v[s]==v[e]){
                s++;
                e--;
            }else{
                return false;
            }
        }
        return true;
    }
};