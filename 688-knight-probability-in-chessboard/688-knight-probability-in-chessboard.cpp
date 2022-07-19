class Solution {
public:
    int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    
    bool isSafe(int x, int y, int n) {
        if(x<0 || y<0 || x>=n || y>=n) return false;
        return true;
    }
    
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<double>> curr(n, vector<double> (n, 0)), next(n, vector<double> (n, 0));
        curr[r][c] = 1.0;
        
        for(int x=0; x<k; x++) {
            
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    
                    for(int y=0;y<8;y++) {
                        int ni = i + dx[y];
                        int nj = j + dy[y];
                        
                        if(isSafe(ni, nj, n)) next[ni][nj] += (curr[i][j]/8);
                    }
                    
                }
            }
            
            curr = next;
            for(int i=0;i<n;i++) for(int j=0;j<n;j++) next[i][j] = 0.0;
        }
        
        double ans = 0.0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) ans += curr[i][j];
        }
        
        return ans;
        
    }
};