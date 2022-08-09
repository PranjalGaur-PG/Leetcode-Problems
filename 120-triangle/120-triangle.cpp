class Solution {
public:
//     int fun(vector<vector<int>> tri, int i, int j, int n, vector<vector<int>>& dp) {
//         if(i == n-1) return tri[i][j];
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int a = fun(tri, i+1, j, n, dp);
//         int b = fun(tri, i+1, j+1, n, dp);
        
//         return dp[i][j] = tri[i][j] + min(a, b);
//     }
    
//     int minimumTotal(vector<vector<int>>& tri) {
//         int n = tri.size();
        
//         vector<vector<int>> dp(n, vector<int> (n, -1));
//         return fun(tri, 0, 0, n, dp);
//     }
    int minTriangle(vector<vector<int>>&nums,int i,int j,vector<vector<int>>&dp){
        
        //base case
        if(i==nums.size()-1){
            return nums[i][j];
        }
        //if already exist
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //case 1 if we go down
        int down = nums[i][j] + minTriangle(nums,i+1,j,dp);
		//case2 if we go diagonal
        int dg = nums[i][j] + minTriangle(nums,i+1,j+1,dp);
        //storing min of both 
        return dp[i][j] = min(down,dg);
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
         vector<vector<int>>dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
         if(triangle.size()==1){
             return triangle[0][0];
         } 
        
         minTriangle(triangle,0,0,dp);                    
         return dp[0][0];
    }
};