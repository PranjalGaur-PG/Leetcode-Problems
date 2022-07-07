class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    void dfs(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 1) {
                
            }
            else {
                dfs(grid, nx, ny);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int cnt = 0, n = grid.size(), m = grid[0].size();
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j]==0) dfs(grid, i, j);   
                }
            }
        }    
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 0){
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return cnt;
        
    }
};