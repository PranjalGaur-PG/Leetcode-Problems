class NumMatrix {
public:
    vector<vector<int>> ans;
    NumMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        ans.resize(n+1, vector<int> (m+1, 0));
        
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(i==0 || j==0) ans[i][j] = 0;
                else if(i==1) ans [i][j] = ans[i][j-1] + mat[i-1][j-1];
                else if(j==1) ans [i][j] = ans[i-1][j] + mat[i-1][j-1];
                else ans[i][j] = mat[i-1][j-1] + ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return ans[row2+1][col2+1] + ans[row1][col1] - ans[row1][col2+1] - ans[row2+1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */