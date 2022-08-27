class Solution {
public:
    int rec(vector<int>& pri, int ind, int buy, vector<vector<int>>& dp, int n) {
        if(ind == n) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy) {
            return dp[ind][buy] = max(-pri[ind] + rec(pri, ind+1, 0, dp, n) , rec(pri, ind+1, 1, dp, n));
        }
        else {
            return dp[ind][buy] = max( pri[ind] + rec(pri, ind+1, 1, dp, n) , rec(pri, ind+1, 0, dp, n));
        }
    }
    
    int maxProfit(vector<int>& pri) {
        
        int n = pri.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        
        dp[n][1] = dp[n][0] = 0;
        
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<2;j++) {
                if(j == 1) dp[i][j] = max(-pri[i] + dp[i+1][0], dp[i+1][1]);
                else       dp[i][j] = max( pri[i] + dp[i+1][1], dp[i+1][0]);
            }
        }
        
        return dp[0][1];
    }
};