class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        vector<int> red[n];
    vector<int> blu[n];
    
    for(auto it:redEdges)
        red[it[0]].push_back(it[1]);
    
    for(auto it:blueEdges)
        blu[it[0]].push_back(it[1]);
    
    
    vector<int> ans(n,-1);
    ans[0]=0;
    
    vector<bool> rvis(n,false); // is that node visited from red edge
    vector<bool> bvis(n,false); // // is that node visited from blue edge
    
    
    int level=0;
    rvis[0]=bvis[0]=1;
    
    queue<pair<int,int>> q;
    q.push({0,-1}); // -1 means I can use any of path , 1 means prev used edge was blue, 0 means prev used is red one
    
    while(!q.empty()) {
        
        int a=q.size();
        for(int i=0;i<a;i++)
        {
            int node=q.front().first;
            int type=q.front().second;
            q.pop();
            
            if(ans[node] == -1) ans[node]=level;
        
            if(type == 1 or type == -1)
            {
                for(auto it:red[node])
                {
                    if(rvis[it] == false)
                    {
                        // rvis[it]=1;
                        q.push({it,0});
                    }
                }
            }
        
            if(type == 0 or type == -1)
            {
                for(auto it:blu[node])
                {
                    if(bvis[it] == false)
                    {
                        bvis[it]=1;
                        q.push({it,1});
                    }
                }
            }
            
        }
        level++;
    }
    return ans;
    }
};