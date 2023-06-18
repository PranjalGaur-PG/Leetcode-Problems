class Solution {
public:
    const int M=1e9+7;
	int f(int i,int j,int mm,int n,vector<vector<int>>& m,vector<vector<int>>& dp)
	{
		if(i<0 or j<0 or i>=mm or j>=n)return 0;

		if(dp[i][j]!=-1)return dp[i][j];

		int ans=1;
		if(i>0 and m[i][j]<m[i-1][j])
		{
			ans+=f(i-1,j,mm,n,m,dp);
		}
		if(i+1<mm and m[i][j]<m[i+1][j])
		{
			ans+=f(i+1,j,mm,n,m,dp);
		}
		if(j>0 and m[i][j]<m[i][j-1])
		{
			ans+=f(i,j-1,mm,n,m,dp);
		}
		if(j+1<n and m[i][j]<m[i][j+1])
		{
			ans+=f(i,j+1,mm,n,m,dp);
		}
		return dp[i][j]=ans%M;
	}
	int countPaths(vector<vector<int>>& matrix) 
	{
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int> (n, -1));
		long long ans=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				ans+=f(i,j,m,n,matrix,dp);
			}
		}
		return ans%M;
	}
};