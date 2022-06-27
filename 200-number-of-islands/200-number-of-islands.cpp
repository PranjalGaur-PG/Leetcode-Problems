class Solution {
public:
    int mvx[4] = {0, 0, 1, -1};
    int mvy[4] = {1, -1, 0, 0};
    
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        grid[i][j] = '0';
        
        for(int x=0;x<4;x++) {
            int nx = i + mvx[x];
            int ny = j + mvy[x];
            
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == '1') dfs(grid, nx, ny, n, m);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        
        return ans;
    }
};