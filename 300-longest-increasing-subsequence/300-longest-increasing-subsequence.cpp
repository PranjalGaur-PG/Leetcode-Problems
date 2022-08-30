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
        
//         vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
//         for(int i=n-1;i>=0;i--) {
//             for(int j=i-1;j>=-1;j--) {
//                 int ans1=0, ans2=0;
//                 if(j == -1 || nums[i]>nums[j]) ans1 = 1 + dp[i+1][i+1];
//                 ans2 = dp[i+1][j+1];

//                 dp[i][j+1] = max(ans1, ans2);
//             }
//         }
        
//         return dp[0][0];
        
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], 1+dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        
        // for(auto it: dp) ans = max(it, ans);
        
        return ans;
    }
};