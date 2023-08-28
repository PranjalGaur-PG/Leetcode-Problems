class Solution {
public:
    int rec(int ind, vector<int>& nums, vector<int>& dp) {
        if(ind == 0) return nums[0];
        if(ind == 1) return max(nums[0], nums[1]);
        if(dp[ind] != -1) return dp[ind];
        
        int p = nums[ind] + rec(ind-2, nums, dp);
        int np = rec(ind-1, nums, dp);
        
        return dp[ind] = max(p, np);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2;i<n;i++) {
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
            
        return dp[n-1];
        
        // return rec(n-1, nums, dp);
    }
};