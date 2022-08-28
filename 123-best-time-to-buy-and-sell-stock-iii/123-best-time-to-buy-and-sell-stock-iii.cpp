class Solution {
public:
    int rec(vector<int>& pri, int ind, int buy, int cap, vector<vector<vector<int>>>& dp) {
        if(ind == pri.size() || cap == 0) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        if(buy) {
            return dp[ind][buy][cap] = max(-pri[ind] + rec(pri,ind+1,0,cap,dp), rec(pri,ind+1,1,cap,dp));
        }
        else {
            return dp[ind][buy][cap] = max(pri[ind] + rec(pri,ind+1,1,cap-1,dp), rec(pri,ind+1,0,cap,dp));
        }
    }
    
    int maxProfit(vector<int>& pri) {
        int n = pri.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return rec(pri, 0, 1, 2, dp);
    }
};