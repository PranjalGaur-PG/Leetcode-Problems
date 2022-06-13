class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
//         int n = tri.size();
        
//         for(int i=1;i<n;i++) {
//             for(int j=0;j<tri[i].size();j++) {
                
//                 if(j>0) tri[i][j] += min(tri[i-1][j], tri[i-1][j-1]);
//                 else tri[i][j] += tri[i-1][j];
            
//             }
//         }
        
//         int ans = INT_MAX;
//         for(int i=0;i<tri[n-1].size();i++) ans = min(ans, tri[n-1][i]);
//         return ans;
            vector<int> res = tri.back();
    for (int i = tri.size()-2; i >= 0; i--) 
        for (unsigned int j = 0; j <= i; j++) 
            res[j] = tri[i][j] + min(res[j], res[j+1]);
    return res[0];

    }
};