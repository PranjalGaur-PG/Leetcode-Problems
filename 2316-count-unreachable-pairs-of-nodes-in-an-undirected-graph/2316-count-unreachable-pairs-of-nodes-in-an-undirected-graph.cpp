class Solution {
public:
    unordered_map<int, int> mp;
    int sz;
    
    void dfs(vector<int> adj[], vector<int>& vis, vector<int>& par, int ind, int parent) {
        vis[ind] = 1;
        par[ind] = parent;
        mp[parent] = max(sz, mp[parent]);
        sz++;
        
        for(int i=0;i<adj[ind].size();i++) {
            if(!vis[adj[ind][i]]) {
                dfs(adj, vis, par, adj[ind][i], parent);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> par(n), vis(n, 0);
        for(int i=0;i<n;i++) par[i] = i;
        
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                mp[i] = 1;
                sz = 1;
                dfs(adj, vis, par, i, i);
            }
        }
        
        long long ans = 0;
        for(int i=0;i<n;i++) {
            ans += (n-mp[par[i]]);
            // cout<<i<<" "<<mp[par[i]]<<' '<<par[i]<<endl;
        }
        
        return ans/2;
        
    }
};