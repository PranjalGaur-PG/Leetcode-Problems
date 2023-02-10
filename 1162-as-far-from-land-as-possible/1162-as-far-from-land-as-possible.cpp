class Solution {
public:
    bool isSafe(int x, int y, int n) {
        if(x<0 || x>=n || y<0 || y>=n) return false;
        return true;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        
        int mx[] = {0, 0, 1, -1};
        int my[] = {1, -1, 0, 0};
        
        // vector<vector<bool>> vis(n, vector<bool> (n, false));
        
        int cnt = 0, ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) {
                    cnt++;
                    q.push({i, j});
                }
            }
        }
        
        if(cnt == 0 || cnt == n*n) return -1;
        
        while(q.size()) {
            int sz = q.size();
            ans++;
            while(sz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++) {
                    int nx = x + mx[i];
                    int ny = y + my[i];
                    
                    if(isSafe(nx, ny, n) && !grid[nx][ny]) {
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return ans-1;
    }
};