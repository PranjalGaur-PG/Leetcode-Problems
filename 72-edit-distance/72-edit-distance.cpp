class Solution {
public:
    int rec(string& s1, string& s2, int n, int m, vector<vector<int>>& dp) {
        if(n<0) return m+1;
        if(m<0) return n+1;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s1[n]==s2[m]) return dp[n][m] = rec(s1, s2, n-1, m-1, dp);
        
        int mvs = 1e6;
        mvs = min(mvs, rec(s1, s2, n-1, m, dp));
        mvs = min(mvs, rec(s1, s2, n, m-1, dp));
        mvs = min(mvs, rec(s1, s2, n-1, m-1, dp));
        
        return dp[n][m] = 1+mvs;
    }
        
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                
                else if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    int mvs = 1e6;
                    mvs = min(mvs, dp[i-1][j]);
                    mvs = min(mvs, dp[i][j-1]);
                    mvs = min(mvs, dp[i-1][j-1]);

                    dp[i][j] = 1+mvs;
                }
            }
        }
        
        return dp[n][m];
    }
};