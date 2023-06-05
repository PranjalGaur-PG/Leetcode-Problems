class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int i=0, row = -1, n = mat.size(), m = mat[0].size();
        
        while(i<n) {
            if(mat[i][m-1] >= tar) {
                row = i;
                break;
            }
            i++;
        }
        
        if(row == -1) return false;
        if(binary_search(mat[row].begin(), mat[row].end(), tar)) return true;
        return false;
    }
};