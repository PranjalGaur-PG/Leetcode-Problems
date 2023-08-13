class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0 ;
        
        vector<bool> prime(n+1, true); 
        prime[0] = false;
        prime[1] = false;
        
        for(int i=2 ; i*i<=n ; i++) {
            for(int j = 2*i;j<=n;j+=i) {
                prime[j] = false;
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++) {
            if(prime[i]==true) count++;
        }
        
        return count;
    }
};