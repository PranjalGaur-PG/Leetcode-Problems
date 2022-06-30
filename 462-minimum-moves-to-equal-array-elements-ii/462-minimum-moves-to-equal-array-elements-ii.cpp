class Solution {
public:
    int minMoves2(vector<int>& nums) {
//         int n = nums.size();
        
//         if(n==1) return 0;
//         if(n==2) return abs(nums[0] - nums[1]);
        
//         sort(nums.begin(), nums.end());
//         int ans = 0;
//         int md = (nums[n/2] + nums[n/2+1])/2;
        
//         for(int i=0;i<n;i++) ans += abs(nums[i] - md);
        
//         return ans;
        
        sort(nums.begin(), nums.end()); 
        int n = nums.size(), res = 0;
        for (int i = 0; i < n/2; ++i) res += (nums[n-1-i]-nums[i]);
        return res;
    }
};