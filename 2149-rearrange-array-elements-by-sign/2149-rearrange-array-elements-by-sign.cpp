class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> p, n;
        for(auto it : nums) {
            if(it>0) p.push(it);
            else n.push(it);
        }
        
        vector<int> ans;
        while(p.size()) {
            ans.push_back(p.front());
            p.pop();
            ans.push_back(n.front());
            n.pop();
        }
        
        return ans;
    }
};