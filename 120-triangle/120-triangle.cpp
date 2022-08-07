class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        if(n==1) return tri[0][0];
        
        int ans = INT_MAX;
        for(int i=1;i<n;i++) {
            for(int j=0;j<=i;j++) {
                if(j==0) tri[i][j] += tri[i-1][j];
                else if(j==i) tri[i][j] += tri[i-1][j-1];
                else tri[i][j] = tri[i][j] + min(tri[i-1][j], tri[i-1][j-1]);
                
                if(i==n-1) ans = min(ans, tri[i][j]);
            }
        }
        
        return ans;
    }
};