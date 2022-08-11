class Solution {
public:
    int rec(vector<int>& nums, int ind, int tar, vector<vector<int>>& dp) {
        
        if(tar == 0) return 1;
        if(ind==0) {
            if(tar == nums[ind]) return 1;
            else return 0;
        }
        
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        int nt = rec(nums, ind-1, tar, dp);
        int t = 0;
        if(nums[ind] <= tar) t = rec(nums, ind-1, tar-nums[ind], dp);
        
        if(t || nt) return dp[ind][tar] = 1;
        return dp[ind][tar] = 0;
    }
        
    bool canPartition(vector<int>& nums) {
        int tar = 0;
        for(auto it : nums) tar += it;
        if(tar%2 != 0) return false;
        
        tar /= 2;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (tar+1, -1));
        
        if(rec(nums, n-1, tar, dp)) return true;
        return false;
    }
};