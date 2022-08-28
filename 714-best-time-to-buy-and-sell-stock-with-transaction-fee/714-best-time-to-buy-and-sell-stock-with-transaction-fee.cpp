class Solution {
public:
    int rec(vector<int>& pri, int ind, int buy, int& fee, vector<vector<int>>& dp) {
        if(ind == pri.size()) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy) return dp[ind][buy] = max(-pri[ind]+rec(pri,ind+1,0,fee,dp), rec(pri,ind+1,1,fee,dp));
        
        return dp[ind][buy] = max(pri[ind]-fee+rec(pri,ind+1,1,fee,dp), rec(pri,ind+1,0,fee,dp));
    }
    
    int maxProfit(vector<int>& pri, int fee) {
        int n = pri.size();
        
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return rec(pri, 0, 1, fee, dp);
    }
};