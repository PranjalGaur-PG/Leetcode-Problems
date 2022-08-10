class Solution {
public:
    int rec(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int i, int j1,int j2, int r,int c)  
        {

        if(j1<0 || j1>=c || j2<0 || j2>=c) return -1000;
        if(i == r-1) {
            if(j1 == j2) return grid[i][j1];
            else return (grid[i][j1] + grid[i][j2]);
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int mx = -1;
        for(int dj1=-1;dj1<2;dj1++) {
            for(int dj2=-1;dj2<2;dj2++) {
                if(j1 == j2) mx = max(mx, grid[i][j1] + rec(grid, dp, i+1, j1+dj1, j2+dj2, r, c));
                else         mx = max(mx, grid[i][j1] + grid[i][j2] + rec(grid, dp, i+1, j1+dj1, j2+dj2, r,                                   c));
            }
        }

        return dp[i][j1][j2] = mx;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int r = grid.size(), c= grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));
        
        return rec(grid, dp, 0, 0, c-1, r, c);
    }
};