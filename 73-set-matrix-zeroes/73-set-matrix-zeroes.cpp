class Solution {
public:
    void fun(vector<vector<int>>& mat, int i, int j) {
        int n;
    }
    
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        
        int r = 0, c = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 0) {
                    if(i==0) r=1;
                    if(j==0) c=1;
                    
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }
        
        if(c) for(int i=0;i<n;i++) mat[i][0] = 0;
        if(r) for(int j=0;j<m;j++) mat[0][j] = 0;
    }
};