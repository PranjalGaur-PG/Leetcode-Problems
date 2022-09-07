class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        
        int i=0, j=n-1;
        while(i<=j) {
            int mid = (i+j)/2;
            if(mid>0 && mid<n-1) {
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
                else if(nums[mid-1]>nums[mid+1]) j = mid-1;
                else i = mid+1;
            }
            else if(mid==0){
                if(nums[mid] > nums[mid+1]) return 0;
                else return 1;
            } 
            else if(mid==n-1) {
                if(nums[mid] > nums[mid-1]) return n-1;
                else return n-2;
            } 
        }
        
        return 0;
    }
};