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
        vector<vector<int>> dp(n, vector<int> (2, -1));
        
        return rec(pri, 0, 1, dp, n);
    }
};