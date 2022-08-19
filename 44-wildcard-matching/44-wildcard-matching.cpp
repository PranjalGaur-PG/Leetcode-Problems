class Solution {
public:
    bool rec(string& s, string& t, int n, int m, vector<vector<int>>& dp) {
        if(n == 0 && m == 0) return true;
        if(n == 0 && m > 0) return false;
        if(m == 0 && n > 0) {
            for(int i=0;i<n;i++) if(s[i] != '*') return false;
            return true;
        }
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n-1] == t[m-1] || s[n-1]=='?') return dp[n][m] = rec(s, t, n-1, m-1, dp);
        else if(s[n-1] == '*') return dp[n][m] = (rec(s,t,n-1,m,dp) || rec(s,t,n,m-1,dp));
        
        return dp[n][m] = false;
    }
        
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        
        return rec(p, s, m, n, dp);
    }
};