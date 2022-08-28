class Solution {
public:
    int rec(vector<int>& nums, int ind, int pre, vector<vector<int>>& dp) {
        if(ind == nums.size()) return 0;
        
        if(dp[ind][pre+1] != -1) return dp[ind][pre+1];
        
        int ans1=0, ans2=0;
        if(pre == -1 || nums[ind]>nums[pre]) ans1 = 1 + rec(nums, ind+1, ind, dp);
        ans2 = rec(nums, ind+1, pre, dp);
        
        return dp[ind][pre+1] = max(ans1, ans2);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return rec(nums, 0, -1, dp);
    }
};