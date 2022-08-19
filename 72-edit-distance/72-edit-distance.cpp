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
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return rec(s1, s2, n-1, m-1, dp);
    }
};