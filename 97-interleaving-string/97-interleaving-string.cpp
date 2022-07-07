class Solution {
public:
    bool fun(string s3, string s1, string s2, int o, int n, int m, vector<vector<int>>& dp) {
        if(n<0 && m<0 && o<0) {
            return true;
        }
        
        if(n>=0 && m>=0 && dp[n][m] != -1) return dp[n][m];
        
        if(n>=0 && s3[o] == s1[n] && m>= 0 && s3[o] == s2[m])
            return dp[n][m] = (fun(s3, s1, s2, o-1, n-1, m, dp) || fun(s3, s1, s2, o-1, n, m-1, dp));
        else if(n>= 0 && s3[o] == s1[n]) return fun(s3, s1, s2, o-1, n-1, m, dp);
        else if(m>= 0 && s3[o] == s2[m]) return fun(s3, s1, s2, o-1, n, m-1, dp);
        else return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {

        int n=s1.size(), m=s2.size(), o=s3.size();
        if(n+m != o) return false;
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return fun(s3, s1, s2, o-1, n-1, m-1, dp);
    } 
};