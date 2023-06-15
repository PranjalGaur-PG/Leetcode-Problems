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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* rec(ListNode* node) {
        if(node == NULL) return NULL;
        if(node->next == NULL) {
            TreeNode* temp = new TreeNode(node->val);
            return temp;
        }
        
        ListNode* prev = node;
        ListNode* fast = node;
        ListNode* slow = node;
        
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = rec(node);
        root->right = rec(slow->next);

        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        return rec(head);
    }
};