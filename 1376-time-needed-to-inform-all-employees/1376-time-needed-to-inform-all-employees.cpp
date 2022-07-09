class Solution {
public:
    vector<vector<int>> children;
    int dfs(int node,vector<int>& informTime)
    {
        int time=0;
        for(int &n:children[node])
            time=max(time,dfs(n,informTime));		
        return informTime[node]+time;				
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        children.resize(n);
        for(int i=0;i<manager.size();i++)				
            if(manager[i]!=-1)
                children[manager[i]].push_back(i);
        return dfs(headID,informTime);
    }
};