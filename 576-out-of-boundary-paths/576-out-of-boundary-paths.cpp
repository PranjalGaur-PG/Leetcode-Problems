class Solution {
public:
    int mod = 1e9+7;
    int dp[51][51][51];
    
    long long fun(int n, int m, int mm, int sr, int sc) {
        if(sr < 0 || sc < 0 || sr>= n || sc >= m) return 1;
        if(mm <= 0) return 0;
        
        if(dp[sr][sc][mm] != -1) return dp[sr][sc][mm];
        
        return dp[sr][sc][mm] = ((fun(n,m,mm-1,sr,sc-1)%mod) + (fun(n,m,mm-1,sr,sc+1)%mod) + (fun(n,m,mm-1,sr-1,sc)%mod) + (fun(n,m,mm-1,sr+1,sc)%mod))%mod;
    }
        
    int findPaths(int m, int n, int mm, int sr, int sc) {
        memset(dp, -1, sizeof(dp));
        
        long long ans = fun(m, n, mm, sr, sc);
        return int(ans % mod);
    }
};