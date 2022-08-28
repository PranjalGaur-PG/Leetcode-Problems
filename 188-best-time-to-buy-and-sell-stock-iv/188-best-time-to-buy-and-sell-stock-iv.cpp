class Solution {
public:
    int rec(vector<int>& pri, int ind, int tnum, int k, vector<vector<int>>& dp) {
        if(ind == pri.size() || tnum == 2*k) return 0;
        
        if(dp[ind][tnum] != -1) return dp[ind][tnum];
        
        if(tnum%2 == 0) {
            return dp[ind][tnum] = max(-pri[ind]+ rec(pri,ind+1,tnum+1,k,dp), rec(pri,ind+1,tnum,k,dp));
        }
        else {
            return dp[ind][tnum] = max( pri[ind]+ rec(pri,ind+1,tnum+1,k,dp), rec(pri,ind+1,tnum,k,dp));
        }
    }
        
    int maxProfit(int k, vector<int>& pri) {
        int n = pri.size();
        
        vector<vector<int>> dp(n, vector<int> (2*k, -1));
        
        return rec(pri, 0, 0, k, dp);
    }
};