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
    int ans, cnt;
    
    void rec(ListNode* node, unordered_set<int>& st) {
        if(!node) return;
        
        if(st.find(node->val) != st.end()) {
            if(!cnt) ans++;
            cnt++;
        }
        else cnt = 0;
        
        rec(node->next, st);
    }
    
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        ans = 0, cnt = 0;
        
        rec(head, st);
        
        return ans;
    }
};