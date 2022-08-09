class Solution {
public:
    int mod = 1e9+7;
    
    int numFactoredBinaryTrees(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        
        map<int,int> index;
        for(int i=0; i<n; i++){
            index[v[i]] = i+1;    
        }
        
        long long dp[n];
        for(int i=0; i<n; i++){
            dp[i] = 1;
            for(int j=0; j<i; j++){
                
                if(v[i]%v[j]==0) {
                    int k = v[i]/v[j];
                    if(index[k]!=0) {
                        
                        long long childTrees = (dp[j] * dp[index[k]-1])%mod;
                        dp[i] = (dp[i] + childTrees)%mod;
                    }
                }        
            }
        }
        //Total no of the trees
        long long int sum=0;
        for(int i=0; i<n; i++){
            sum = (sum + dp[i])%mod;
        }
        return sum;
    }
};