class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)  {
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int x = click[0], y = click[1];
        if(board[x][y] == 'M')
            board[x][y] = 'X';
        else
            dfs(board, x, y, dirs);

        return board;
    }

    void dfs(vector<vector<char>>& board, int x, int y, vector<pair<int, int>> &dirs) {
        int m = board.size(), n = board[0].size();
        if(x <0 || x >=m || y < 0 || y >= n || board[x][y] != 'E' ) return;

        int mine = adjMine(board, x, y, dirs);

        if(mine > 0) board[x][y] = '0' + mine;
        else {
            board[x][y] = 'B';

            for(auto dir: dirs) dfs(board, x + dir.first, y + dir.second, dirs);
        }
    }

    int adjMine(vector<vector<char>>& board, int x, int y, vector<pair<int, int>> &dirs) 
    {
        int m = board.size(), n = board[0].size(), cnt = 0;

        for(auto dir: dirs)
        {
            int i = x + dir.first;
            int j = y + dir.second;

            if (0 <= i && i < m && 0 <= j && j < n && board[i][j] == 'M') cnt++;
        }
        return cnt;
    }    
};