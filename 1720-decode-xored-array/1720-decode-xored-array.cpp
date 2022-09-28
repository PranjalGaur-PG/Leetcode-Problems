class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        
        for(auto it : encoded) {
            first = first ^ it;
            ans.push_back(first);
        }
        
        return ans;
    }
};