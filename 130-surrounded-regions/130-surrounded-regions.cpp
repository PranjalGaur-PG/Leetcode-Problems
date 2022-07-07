class Solution {
public:
    int mvx[4] = {0,0,-1,1};
    int mvy[4] = {-1,1,0,0};
    
    bool isSafe(int i, int j, int n, int m) {
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j, int n, int m) {
        vis[i][j] = 1;
        
        for(int x=0;x<4;x++) {
            int ni = i + mvx[x];
            int nj = j + mvy[x];
            
            if(isSafe(ni, nj, n, m) && board[ni][nj]=='O' && vis[ni][nj]==0)
                dfs(board, vis, ni, nj, n, m);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 || j==0 || i==n-1 || j==m-1) {
                    if(board[i][j]=='O' && !vis[i][j]) dfs(board, vis, i, j, n, m);
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]=='O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};