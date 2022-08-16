class Solution {
public:
    int rec(string& s1, string& s2, int n1, int n2, vector<vector<int>>& dp) {
        if(n1 < 0 || n2 < 0) return 0;
        if(dp[n1][n2] != -1) return dp[n1][n2];
        
        if(s1[n1] == s2[n2]) return dp[n1][n2] = (1 + rec(s1, s2, n1-1, n2-1, dp) );
        
        return dp[n1][n2] =  max( rec(s1, s2, n1-1, n2, dp), rec(s1, s2, n1, n2-1, dp)) ;    
    }
        
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));
        
        for(int i=0;i<=n1;i++) {
            for(int j=0;j<=n2;j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};