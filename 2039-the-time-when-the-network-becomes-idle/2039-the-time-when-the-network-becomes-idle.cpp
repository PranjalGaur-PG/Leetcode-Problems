class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edg, vector<int>& pat) {
        int n = pat.size();
        vector<int> vis(n, -1);
        
        vector<int> adj[n];
        for(auto it : edg) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int> q;
        q.push(0);
        vis[0] = 0;
        
        int t = 0;
        while(q.size()) {
            int sz = q.size();
            t++;
            while(sz--) {
                int ind = q.front();
                q.pop();
                
                for(auto it : adj[ind]) {
                    if(vis[it] == -1) {
                        vis[it] = t;
                        q.push(it);
                    }
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i=1;i<n;i++){
            int left = ceil((vis[i]*2.0)/pat[i]) - 1;
            
            int remainStart = vis[i]*2 - left*pat[i]; 
            
            ans = max(ans, vis[i]*2 - remainStart + vis[i]*2);
        }
        return ans + 1;
    }
};