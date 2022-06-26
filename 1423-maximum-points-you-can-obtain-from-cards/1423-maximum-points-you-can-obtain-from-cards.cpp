class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        vector<int> f(n+1, 0), b(n+1, 0);
        
        for(int i=1;i<=n;i++) f[i] += (f[i-1]+cp[i-1]);
        for(int i=n-1;i>=0;i--) b[i] += (b[i+1] + cp[i]);
        reverse(b.begin(), b.end());
        
        for(auto it : f) cout<<it<<" ";
        cout<<endl;
        for(auto it : b) cout<<it<<" ";
        cout<<endl;
        
        int ans = INT_MIN;
        for(int i=0;i<=k;i++) {
            ans = max(ans, f[i]+b[k-i]);
        }
            
        return ans;
    }
};