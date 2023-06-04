class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        set<int> row, col;
        int n = mat.size(), m = mat[0].size();
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!mat[i][j]) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(row.find(i)!=row.end() || col.find(j)!=col.end()) {
                    mat[i][j] = 0;
                }
            }
        }
        
        
    }
};