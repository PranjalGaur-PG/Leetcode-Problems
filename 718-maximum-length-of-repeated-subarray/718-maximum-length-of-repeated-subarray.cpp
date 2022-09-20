class Solution {
public:
    int rec(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2, vector<vector<int>>& dp) {
        if(ind1==-1 || ind2==-1) return 0;
        
        if(nums1[ind1]==nums2[ind2]) return 1 + rec(nums1, nums2, ind1-1, ind2-1, dp);
        
        return max( rec(nums1, nums2, ind1-1, ind2, dp), rec(nums1, nums2, ind1, ind2-1, dp));
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size(), n2 = nums2.size();
//         vector<vector<int>> dp(n1, vector<int> (n2, -1));
        
//         return rec(nums1, nums2, n1-1, n2-1, dp);
        
        int l1=nums1.size(), l2=nums2.size(),ans=0;
        int i,j,dp[l1+1][l2+1];
        for(i=0;i<=l1;i++) for(j=0;j<=l2;j++) if(i==0 || j==0) dp[i][j]=0;
        for(i=1;i<=l1;i++) {
            for(j=1;j<=l2;j++) {
                if(nums1[i-1]==nums2[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        } 
        return ans;
    }
};