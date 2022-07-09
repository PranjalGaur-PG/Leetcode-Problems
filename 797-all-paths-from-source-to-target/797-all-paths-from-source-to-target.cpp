class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int> vis, int ind, vector<int> temp, int n, 
            vector<vector<int>>& ans) {
        
        temp.push_back(ind);
        vis[ind] = 1;
        
        if(ind == n-1) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<graph[ind].size();i++) {
            int x = graph[ind][i];
            if(!vis[x]) {
                dfs(graph, vis, x, temp, n, ans);
            }
        }
    } 
        
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        
        vector<int> vis(n, 0), temp;
        temp.push_back(0);
        
        for(int i=0;i<graph[0].size();i++) {
            vis[0] = 1;
            dfs(graph, vis, graph[0][i], temp, n, ans);
        }
        
        return ans;
    }
};