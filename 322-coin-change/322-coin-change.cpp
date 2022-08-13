class Solution {
public:
    int rec(vector<int>& coins, int amt, int ind, vector<vector<int>>& dp) {
        
        if(ind == 0) {
            if(amt%coins[ind] == 0) return amt/coins[ind];
            else return 1e6;
        }
        
        if(dp[ind][amt] != -1) return dp[ind][amt];
        
        int nt = rec(coins, amt, ind-1, dp);
        int t = 1e6;
        if(coins[ind] <= amt) t = 1 + rec(coins, amt-coins[ind], ind, dp);
        
        return dp[ind][amt] = min(t, nt);
    }
        
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = rec(coins, amount, n-1, dp);
        
        if(ans >= 1e6) return -1;
        return ans;
    }
};