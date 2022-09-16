class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int INF = 1e9, ans = -INF, n = (int)size(nums), m = (int)size(mul);
        vector<vector<int>> dp(m+1, vector<int>(m+1));
        for (int l = 0; l <= m; ++l){ // l -> num of left element taken 
            for (int r = l?0:1; l+r <= m; ++r){ // r -> num of right element taken
                int a = l? dp[l-1][r] + mul[l+r-1] * nums[l-1] : -INF; // if we take the leftmost element
                int b = r? dp[l][r-1] + mul[l+r-1] * nums[n-r] : -INF; // if we take the rightmost element
                dp[l][r] = max(a, b); // take the max of the two.
                if (l+r == m){ // update answer when it is exactly m
                    ans = max(ans, dp[l][r]);
                }
            }
        }
        return ans;
    }
};