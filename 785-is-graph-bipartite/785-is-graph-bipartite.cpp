class Solution {
public:
    bool fun(vector<vector<int>> adj, vector<int>& col, int i) {
        
        for(int x=0;x<adj[i].size();x++) {
            if(col[adj[i][x]] == -1) {
                col[adj[i][x]] = 1 - col[i];
                if(!fun(adj, col, adj[i][x])) return false;
            }
            else if(col[adj[i][x]] == col[i]) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);
        
        for(int i=0;i<n;i++) {
            if(col[i] == -1) {
                col[i] = 0;
                if(!fun(graph, col, i)) return false;
            }
        }
        
        return true;
    }
};