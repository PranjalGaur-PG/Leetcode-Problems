// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>>ans;
    void fun(vector<vector<int>>&grid,int i,int j,vector<int>&d)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size())
        return;
         if(i==grid.size()-1 && j==grid[i].size()-1)
         {
             ans.push_back(d);
             return;
         }
         d.push_back(grid[i][j]);
         fun(grid,i+1,j,d);
         fun(grid,i,j+1,d);
         d.pop_back();
    }
       vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
       {
           // code here
           vector<int>d;
           fun(grid,0,0,d);
           for(int i=0;i<ans.size();i++)
           ans[i].push_back(grid[n-1][m-1]);
           return ans;
       }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends