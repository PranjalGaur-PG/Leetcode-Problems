class Solution {
public:
    
    int Kadane(vector<int> v, int k) {
        int n=v.size(),sum=0,i,ans=INT_MIN;
        
        set<int> s;
        s.insert(0);
        for(i=0;i<n;i++) {
            sum += v[i];
            
            auto it = s.lower_bound(sum-k);
            if(it != s.end()) {
                int val = *it;
                ans = max(ans,sum-val);
            }
            s.insert(sum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& mat, int kk) {
        int n=mat.size(), m=mat[0].size(), i,j,k, c=0, ans = INT_MIN;
        
        for(i=0;i<m;i++) {
            vector<int> v(n,0);
            for(j=i;j<m;j++) {
                for(k=0;k<n;k++) v[k] += mat[k][j];
                
                c = Kadane(v,kk);
                ans = max(ans,c);
            }
        }
        return ans;
    }
};