class Solution {
public:
    int mvx[4] = {0,0,1,-1};
    int mvy[4] = {1,-1,0,0};
    
    bool isSafe(int i, int j, int n, int m) {
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> ans(n, vector<int> (m, -1));
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!mat[i][j]) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        
        while(q.size()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int x = 0; x<4; x++) {
                int ni = i + mvx[x];
                int nj = j + mvy[x];
                
                if(isSafe(ni, nj, n, m) && ans[ni][nj]==-1) {
                    ans[ni][nj] = 1 + ans[i][j];
                    q.push({ni, nj});
                }
            }
        }
        
        return ans;
    }
};