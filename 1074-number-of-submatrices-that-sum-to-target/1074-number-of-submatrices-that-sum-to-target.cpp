class Solution {
public:
    int ret = 0;
    void func(int r1, int r2, int& target, vector<vector<int>>& matrix){
        unordered_map<int, int> m;
        m[0]++;
        for(int i=0; i<matrix[0].size(); i++){
            int tmp = matrix[r2][i];
            if(r1 != 0) tmp  -= matrix[r1-1][i];
            if(m.count(tmp - target))ret += m[tmp - target];
            m[tmp]++;
        }
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        for(int i=1; i<matrix.size(); i++){
            matrix[i][0] += matrix[i-1][0];
        }
        for(int i=1; i<matrix[0].size(); i++){
            matrix[0][i] += matrix[0][i-1];
        }
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                matrix[i][j] += matrix[i][j-1] + matrix[i-1][j] - matrix[i-1][j-1];
            }
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=i; j<matrix.size(); j++){
                func(i, j, target, matrix);
            }
        }
        return ret;
    }
};