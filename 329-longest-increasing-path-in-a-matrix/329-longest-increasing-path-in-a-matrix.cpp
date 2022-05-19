class Solution {
public:
//     int ans = INT_MIN;  
//     bool isSafe(int i,int j,int n,int m) {
//         if(i<0 || i>=n || j<0 || j>=m) return false;
//         return true;
//     }
//     int mv[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    
//     void dfs(vector<vector<int>>& mat,int i,int j,int n,int m,int t,int p) {
//         // if(!isSafe(i,j,n,m) || mat[i][j]<0 || mat[i][j]<p) return;
            
//         t++;
//         ans = max(t,ans);
//         p = mat[i][j];
//         mat[i][j] = -1;
//         for(int x=0;x<4;x++) {
//             int ni = i+mv[i][0];
//             int nj = j+mv[i][1];
//             if(isSafe(ni,nj,n,m) && mat[ni][nj]>0 && mat[ni][nj]>p)
//                 dfs(mat,ni,nj,n,m,t+1,mat[i][j]);
//         }
//         mat[i][j] = p;
//     }
//     int longestIncreasingPath(vector<vector<int>>& mat) {
//         int n = mat.size(), m=mat[0].size(), i,j;
//         int t;
//         for(i=0;i<n;i++) {
//             for(j=0;j<m;j++) {
//                 t = 0;
//                 dfs(mat,i,j,n,m,t,-1);
//             }
//         }
//         return ans;
//     }
    
    int dp[201][201];
    int dfs(vector<vector<int>> &mat, int i, int j, int pre) {
        if (i < 0 || j < 0 || i == mat.size() || j == mat[0].size() || pre >= mat[i][j])
            return 0;
        if (dp[i][j]) return dp[i][j];
        int l = dfs(mat, i, j - 1, mat[i][j]);
        int r = dfs(mat, i, j + 1, mat[i][j]);
        int u = dfs(mat, i - 1, j, mat[i][j]);
        int d = dfs(mat, i + 1, j, mat[i][j]);
        return dp[i][j] = max({l, r, u, d}) + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxVal = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                maxVal = max(maxVal, dfs(matrix, i, j, -1));
        return maxVal;
    }
};