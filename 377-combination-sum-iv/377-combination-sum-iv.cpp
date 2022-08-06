class Solution {
public:
    int m[2001];
    
    int combinationSum4(vector<int>& nums, int t) {
        memset(m,-1,sizeof(m));
        int ans = fun(nums,t);
        return ans;
    }
    
    int fun(vector<int>& nums, int t) {
        if(m[t] != -1) return m[t];
        
        // if(t==0) return 1;
        if(t<=0) return (t==0);
        
        int i,n = nums.size(),c=0,x;
        for(i=0;i<n;i++) {
            if(t-nums[i] >=0) {
                c += fun(nums,t-nums[i]);
            }
        }
        m[t] = c;
        return c;
    }
};