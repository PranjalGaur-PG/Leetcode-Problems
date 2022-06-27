// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> ans;
    void BFS(int v,vector<int> adj[]) {
        bool vis[v+1] = {false};
        queue<int> q;
        q.push(0);
        vis[0] = true;
        
        while(q.size()!=0) {
            int x = q.front();
            q.pop();
            
            ans.push_back(x);
            for(int i=0;i<adj[x].size();i++) {
                if(vis[adj[x][i]]==false) {
                    vis[adj[x][i]] = true;
                    q.push(adj[x][i]);
                }
            }
        }
        
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        int i,j,x;
        
        BFS(v,adj);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends