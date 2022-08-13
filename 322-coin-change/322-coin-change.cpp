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
        
        vector<vector<int>> dp(n, vector<int> (amount+1, 1e6));
        // int ans = rec(coins, amount, n-1, dp);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<=amount;j++) {
                if(i==0) {
                    if(j%coins[i] == 0) dp[i][j] = j/coins[i];
                }
                else {
                    int t = 1e6;
                    if(coins[i] <= j) t = 1 + dp[i][j-coins[i]];
                    int nt = dp[i-1][j];

                    dp[i][j] = min(t, nt);
                }
            }
        }
        
        if(dp[n-1][amount] >= 1e6) return -1;
        return dp[n-1][amount];
    }
};