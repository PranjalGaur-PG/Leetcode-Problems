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
    ListNode* rec(ListNode* node) {
        if(!node) return NULL;
        
        int cnt = 0;
        while(node->val != 0) {
            cnt += node->val;
            node = node->next;
        }
        
        node->val = cnt;
        node->next = rec(node->next);
        return node;
    }
    
    ListNode* mergeNodes(ListNode* head) {
        head->next = rec(head->next);
        return head->next;
    }
};