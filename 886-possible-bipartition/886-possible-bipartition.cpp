class Solution {
public:
    bool dfs(vector<int> adj[], vector<int>& col, int ind) {
        
        for(int i=0;i<adj[ind].size();i++) {
            if(col[adj[ind][i]] == -1) {
                col[adj[ind][i]] = 1 - col[ind];
                if(!dfs(adj, col, adj[ind][i])) return false;
            }
            else if(col[adj[ind][i]] == col[ind]) return false;
        }
        
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vector<int> adj[n];
        
        for(auto it : dis) {
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        
        bool flag = true;
        vector<int> col(n, -1);
        for(int i=0;i<n;i++) {
            if(col[i]==-1) {
                col[i] = 0;
                if(!dfs(adj, col, i)) return false;
            }
        }
        
        return true;
    }
};