// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    void dfs(vector<int> adj[], vector<int>& vis, vector<int>& ans, int ind) {
        ans.push_back(ind);
        vis[ind] = 1;
        
        for(int i=0;i<adj[ind].size();i++) {
            if(!vis[adj[ind][i]]) {
                dfs(adj, vis, ans, adj[ind][i]);
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        
        vector<int> ans, vis(v, 0);
        
        for(int i=0;i<v;i++) {
                if(!vis[i]) dfs(adj, vis, ans, i);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends