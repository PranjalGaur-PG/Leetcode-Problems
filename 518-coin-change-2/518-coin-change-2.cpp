class Solution {
public:
    int rec(vector<int>& coins, int amt, int ind, vector<vector<int>>& dp) {
        // if()
        if(amt == 0) return 1;
        if(ind<0) {
            if(amt == 0) return 1;
            return 0;
        }
        
        if(dp[ind][amt] != -1) return dp[ind][amt];
        
        int nt = rec(coins, amt, ind-1, dp);
        int t = 0;
        if(coins[ind] <= amt) t = rec(coins, amt-coins[ind], ind, dp);
        
        return dp[ind][amt] = t+nt;
    }
    
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int> (amt+1, -1));
        return rec(coins, amt, n-1, dp);
    }
};