class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        
        stack<pair<int, int>> st;
        int mn = nums[0];
        
        for(int i=1;i<n;i++) {
            while(st.size() && nums[i] >= st.top().first) st.pop();
            
            if(st.size() and nums[i]>st.top().second) return true;
            
            st.push({nums[i], mn});
            mn = min(mn, nums[i]);
        }
        
        return false;
    }
};