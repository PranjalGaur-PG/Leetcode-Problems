class Solution {
public:
    int fun(vector<vector<int>> board, int i, int j, int n, int m) {
        int cnt =0;
        
        if(i>0 && board[i-1][j]) cnt++;
        if(j>0 && board[i][j-1]) cnt++;
        if(i<n-1 && board[i+1][j]) cnt++;
        if(j<m-1 && board[i][j+1]) cnt++;
        if(i>0 && j>0 && board[i-1][j-1]) cnt++;
        if(i>0 && j<m-1 && board[i-1][j+1]) cnt++;
        if(i<n-1 && j>0 && board[i+1][j-1]) cnt++;
        if(i<n-1 && j<m-1 && board[i+1][j+1]) cnt++;
        
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(), m = board[0].size();
        
        vector<vector<int>> mat(n, vector<int> (m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) mat[i][j] = board[i][j];
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int cnt = fun(board, i, j, n, m);
                if(board[i][j]) {
                    if(cnt < 2) mat[i][j] = 0;
                    else if(cnt < 4) mat[i][j]=1;
                    else mat[i][j] = 0;
                }
                else {
                    if(cnt == 3) mat[i][j]=1;
                    else mat[i][j] = 0;
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) board[i][j] = mat[i][j];
        }
    }
};