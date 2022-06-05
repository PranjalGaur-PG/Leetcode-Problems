class Solution {
public:
    bool canAddQueen(int row,int col,vector<vector<int>>&queens){
        for(int i=0;i<queens.size();i++){
            int dx=abs(row-queens[i][0]);
            int dy=abs(col-queens[i][1]);
            if(dx==0||dy==0||dx==dy)
                return false;
        }
        return true;
    }
    void solve(int row,vector<vector<string>> &res,vector<vector<char>> &temp,int n,vector<vector<int>>&queens){
        if(queens.size()==n){
            vector<string> tmp;
            for(int i=0;i<n;i++){
                string st="";
                for(int j=0;j<temp[i].size();j++){
                    st+=temp[i][j];
                }
                tmp.push_back(st);
            }
            res.push_back(tmp);
        }
        for(int c=0;c<n;c++){
            if(canAddQueen(row,c,queens)){
                temp[row][c]='Q';
                queens.push_back({row,c});
                solve(row+1,res,temp,n,queens);
                temp[row][c]='.';
                queens.pop_back();
            }
            
        }
    }
    int solveNQueens(int n) {
        vector<vector<char>> temp(n,vector<char>(n,'.'));
        vector<vector<string>> res;
        vector<vector<int>> queens;
        solve(0,res,temp,n,queens);
        return res.size();
    }
    
    int totalNQueens(int n) {
        return solveNQueens(n);
    }
};