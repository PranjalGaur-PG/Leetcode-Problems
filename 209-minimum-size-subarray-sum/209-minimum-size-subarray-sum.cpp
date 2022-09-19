class Solution {
public:
    bool works(vector<int>& nums, int sz, int tar, int n) {
        int sum = 0;
        for(int i=0;i<sz;i++) sum += nums[i];
        
        for(int i=sz;i<n;i++) {
            if(sum >= tar) return true;
            sum += (nums[i]-nums[i-sz]);
        }
        
        return false;
    }
        
    int minSubArrayLen(int tar, vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0, sum=0, ans=INT_MAX;
        
        while(j<n) {
            sum += nums[j]; 
            j++;
            
            while(sum >= tar) {
                sum -= nums[i]; 
                i++;
                ans = min(ans, j-i+1);
            }
        } 
        
        return (ans == INT_MAX ? 0 : ans);
        
//         int i=1, j=n, ans = INT_MAX;
        
//         while(i<=j) {
//             int mid = i+ (j-i)/2;
            
//             if(works(nums, mid, tar, n)) {
//                 ans = mid;
//                 j=mid-1;
//             }
//             else i = mid+1;
//         }
        
//         return (ans == INT_MAX ? 0 : ans);
    }
};