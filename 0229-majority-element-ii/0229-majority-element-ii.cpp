class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mp;
        set<int> st;
        
        for(auto it : nums) {
            mp[it]++;
            if(3*mp[it] > nums.size() && st.find(it)==st.end()) {
                ans.push_back(it);
                st.insert(it);
            }
        }
        
        return ans;
    }
};