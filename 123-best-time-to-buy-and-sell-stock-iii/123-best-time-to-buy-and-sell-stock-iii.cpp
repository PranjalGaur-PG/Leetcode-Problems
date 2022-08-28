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
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
        
        for(int i=n;i>=0;i--) {
            for(int j=0;j<2;j++) {
                for(int k=0;k<3;k++) {
                    if(i == n || k == 0) dp[i][j][k] = 0;
                    else if(j==1) dp[i][j][k] = max(-pri[i]+ dp[i+1][0][k], dp[i+1][1][k]);
                    else dp[i][j][k] = max(pri[i]+ dp[i+1][1][k-1], dp[i+1][0][k]);
                }
            }
        }
        
        return dp[0][1][2];
    }
};