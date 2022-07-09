class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<int>& vis, int ind) {
        vis[ind] = 1;
        
        for(int i=0;i<rooms[ind].size();i++) {
            int x = rooms[ind][i];
            
            if(!vis[x]) dfs(rooms, vis, x);
        }
    }
        
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<int> vis(n, 0);
        vis[0] = 1;
        for(int i=0;i<rooms[0].size();i++) {
            if(!vis[rooms[0][i]]) dfs(rooms, vis, rooms[0][i]);
        }
        
        for(auto it : vis) if(!it) return false;
        return true;
    }
};