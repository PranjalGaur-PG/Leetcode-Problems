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
        
        vector<vector<int>> after(2, vector<int> (3, 0));
        vector<vector<int>> cur  (2, vector<int> (3, 0));
        
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<2;j++) {
                for(int k=1;k<3;k++) {
                    if(j==1) cur[j][k] = max(-pri[i]+ after[0][k], after[1][k]);
                    else cur[j][k] = max(pri[i]+ after[1][k-1], after[0][k]);
                }
            }
            after = cur;
        }
        
        return after[1][2];
    }
};