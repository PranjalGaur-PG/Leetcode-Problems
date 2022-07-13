/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(q.size()) {
            vector<int> temp;
            
            int n = q.size();
            while(n--) {
                Node* f = q.front();
                q.pop();
                temp.push_back(f->val);
                
                for(int i=0; i < f->children.size(); i++) {
                    q.push(f->children[i]);
                }
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};