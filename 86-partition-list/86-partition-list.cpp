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
    ListNode* partition(ListNode* head, int x) {
        ListNode* root= head;
        
        vector<int> l, g;
        int cnt = 0;
        
        while(root) {
            if(root->val < x) l.push_back(root->val);
            else g.push_back(root->val);
            root = root->next;
        }
        
        root = head;
        int i=0, j=0;
        while(root) {
            if(i<l.size()) root->val = l[i++];
            else root->val = g[j++];
            
            root = root->next;
        }
        
        return head;
    }
};