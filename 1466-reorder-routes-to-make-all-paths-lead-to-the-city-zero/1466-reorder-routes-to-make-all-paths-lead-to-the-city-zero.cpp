class Solution {
public:
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<int> vis(n,0);
        vector<int> adj[n], back[n];
        
        for(int i=0;i<conn.size();i++) {
            adj[conn[i][0]].push_back(conn[i][1]);
            back[conn[i][1]].push_back(conn[i][0]);
        }
        
        queue<int> q;
        q.push(0);
        int cnt = 0;
        while(q.size()!=0) {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            
            for(auto j : adj[node]) {
                if(!vis[j]) {
                    cnt++;
                    q.push(j);
                }
            }
            for(auto j : back[node]) {
                if(!vis[j]) q.push(j);
            }
        }
        return cnt;
    }
};