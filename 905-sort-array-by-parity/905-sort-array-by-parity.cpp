class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> o, e;
        for(auto it : nums) {
            if(it%2) o.push_back(it);
            else e.push_back(it);
        }
        
        vector<int> ans(e.begin(), e.end());
        for(auto it : o) ans.push_back(it);
        
        return ans;
    }
};