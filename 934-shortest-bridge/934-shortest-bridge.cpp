class Solution {
public:
    int mvx[4] = {0,0,1,-1};
    int mvy[4] = {1,-1,0,0};
    
    bool isSafe(int x, int y, int n, int m) {
        if(x<0 || y<0 || x>=n || y>=m) return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        grid[i][j] = -1;
        
        for(int x=0;x<4;x++) {
            int ni = i + mvx[x];
            int nj = j + mvy[x];
            
            if(isSafe(ni, nj, n, m) and grid[ni][nj]==1) dfs(grid, ni, nj, n, m);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        bool flg=true;
        queue<pair<int, int>> q;
        for(int i=0;i<n && flg;i++) {
            for(int j=0;j<m && flg;j++) {
                if(grid[i][j]==1) {
                    dfs(grid, i, j, n, m);
                    flg = false;
                }
            }
        }
        
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]==-1) q.push({i, j});
        
        int cnt=-1;
        while(q.size()) {
            int sz = q.size();
            
            cnt++;
            while(sz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++) {
                    int nx = x + mvx[i];
                    int ny = y + mvy[i];
                    
                    if(isSafe(nx, ny, n, m) && grid[nx][ny] == 1) return cnt;
                    if(isSafe(nx, ny, n, m) && grid[nx][ny]==0) {
                        grid[nx][ny] = -1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return 0;
    }
};