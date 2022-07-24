class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
//         int n = mat.size(), m = mat[0].size();
        
//         for(int x=0;x<n;x++) {
//             int i=0, j = m-1;
//             while(i<=j) {
//                 int mid = (i+j)/2;
//                 cout<<mat[x][mid]<<" ";
//                 if(mat[x][mid]==tar) return true;
//                 else if(mat[x][mid] > tar) j = mid-1;
//                 else i = mid+1;
//             }
//             cout<<endl;
//         }
        
//         return false;
        
        int m = mat.size();
        if (m == 0) return false;
        int n = mat[0].size();

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (mat[i][j] == tar)
                return true;
            else if (mat[i][j] > tar) {
                j--;
            } else 
                i++;
        }
        return false;
    }
};