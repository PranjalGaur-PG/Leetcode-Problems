class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int i=0, j=n-1;
        if(n==1 || nums[0]<nums[n-1]) return nums[0];
        
        while(i<=j) {
            int mid = (i+j)/2;
            if(mid>0 && nums[mid]<nums[mid-1]) return nums[mid];
            if(mid<n-1 && nums[mid]>nums[mid+1]) return nums[mid+1];
            
            if(nums[mid]>nums[i]) i = mid+1;
            else j = mid-1;
        }
        
        return -1;
    }
};