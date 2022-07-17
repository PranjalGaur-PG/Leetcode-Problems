class Solution {
public:
    const int mod = 1e9+7;
    int kInversePairs(int n, int k) {
       int dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        dp[1][0]=1;
        for(int i=2; i<=n; i++){
            long long sum=0;
            for(int j=0;j<=min(k,((i*(i-1))/2)); j++){
                if(j<i){
                    sum = (sum+dp[i-1][j])%mod;
                }else{
                    sum = (sum-dp[i-1][j-i]+mod)%mod;
                    sum = (sum+dp[i-1][j])%mod;
                }
                dp[i][j] = sum;
            }
        }
        return dp[n][k];
    }
};