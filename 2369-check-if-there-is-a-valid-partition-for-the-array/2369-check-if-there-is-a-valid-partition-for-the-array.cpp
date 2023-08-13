class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        
        if(nums[0]==nums[1]) dp[1] = true;
        if(n>2 && ((nums[0]==nums[1] && nums[1]==nums[2]) || nums[2]-nums[1]== 1 && nums[1]-nums[0] == 1)) dp[2] = true;
        
        for(int i=3;i<n;i++) {
            if(dp[i-2] && nums[i]==nums[i-1]) dp[i] = true;
            else if(dp[i-3] && nums[i]==nums[i-1] && nums[i-1]==nums[i-2]) dp[i] = true;
            else if(dp[i-3] && nums[i]-nums[i-1] == 1 && nums[i-1]-nums[i-2] == 1) dp[i] = true;
        }
        
        return dp[n-1];
    }
};