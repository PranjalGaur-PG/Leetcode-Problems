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
        
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return rec(text1, text2, n1-1, n2-1, dp);
    }
};