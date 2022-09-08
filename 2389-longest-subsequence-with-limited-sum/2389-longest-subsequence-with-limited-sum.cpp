class Solution {
public:
    int fun(vector<int>& nums, int sum, int n) {
        int i=0, j=n-1, res;
        if(sum < nums[0]) return 0;
        
        while(i<=j) {
            int mid = (i+j)/2;
            if(nums[mid]<=sum) {
                res = mid;
                i = mid+1;
            }
            else j=mid-1;
        }
        
        return res+1;
    }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& que) {
        int n = nums.size(), m = que.size();
        sort(nums.begin(), nums.end());
        
        vector<int> ans(m);
        for(int i=1;i<n;i++) nums[i] += nums[i-1];
        
        for(int i=0;i<m;i++) {
            ans[i] = fun(nums, que[i], n);
        }
        
        return ans;
    }
};