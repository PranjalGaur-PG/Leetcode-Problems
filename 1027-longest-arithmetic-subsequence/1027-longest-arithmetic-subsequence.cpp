class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int dp[n][1005];     //max common difference is 500 and minimum is -500...so we take 1005 size
        for(int i=0;i<n;i++){
            for(int j=0;j<=1000;j++){
                dp[i][j]=1;
            }
        }
        int ans=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                int d=nums[j]-nums[i];
                dp[i][d+500]=max(1+dp[j][d+500],dp[i][d+500]);   //to avoid negative index we add 500 in d
                ans=max(ans,dp[i][d+500]);
            }
        }
        return ans;
    }
};