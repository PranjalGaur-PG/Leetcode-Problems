class Solution {
public:
    void dfs(vector<int> adj[], vector<bool>& vis, int ind) {
        vis[ind] = true;
        
        for(auto it : adj[ind]) if(!vis[it]) dfs(adj, vis, it);
        
    }
    
    int findCircleNum(vector<vector<int>>& roads) {
        int n = roads.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i != j && roads[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> vis(n, false);
        int ans = 0;
        
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                ans++;
                dfs(adj, vis, i);
            }
        }
        return ans;
    }
};