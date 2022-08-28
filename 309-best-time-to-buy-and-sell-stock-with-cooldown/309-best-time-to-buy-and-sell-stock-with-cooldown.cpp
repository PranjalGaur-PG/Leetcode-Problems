class Solution {
public:
    int rec(vector<int>& pri, int ind, int buy, vector<vector<int>>& dp) {
        if(ind >= pri.size()) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy) {
            return dp[ind][buy] = max(-pri[ind] + rec(pri, ind+1, 0, dp), rec(pri, ind+1, 1, dp));
        }
            return dp[ind][buy] = max( pri[ind] + rec(pri, ind+2, 1, dp), rec(pri, ind+1, 0, dp));
    }
    
    int maxProfit(vector<int>& pri) {
        int n = pri.size();
        
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return rec(pri, 0, 1, dp);
    }
};