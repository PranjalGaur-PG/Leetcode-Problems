class Solution {
public:
    int findMin(vector<int>& nums, int n) {
        int i=0, j=n-1;
        if(n==1 || nums[0]<nums[n-1]) return 0;
        
        while(i<=j) {
            int mid = (i+j)/2;
            if(mid>0 && nums[mid]<nums[mid-1]) return mid;
            if(mid<n-1 && nums[mid]>nums[mid+1]) return mid+1;
            
            if(nums[mid]>nums[i]) i = mid+1;
            else j = mid-1;
        }
        return -1;
    }
    
    int BS(vector<int>& nums, int i, int j, int tar) {
        while(i<=j) {
            int mid = (i+j)/2;
            if(nums[mid] == tar) return mid;
            else if(nums[mid] > tar) j = mid-1;
            else i = mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1) {
            if(nums[0]==target) return 0;
            return -1;
        }
        
        int ind = findMin(nums, n);
        
        int ind1 = BS(nums, 0, ind-1, target);
        int ind2 = BS(nums, ind, n-1, target);
        
        cout<<ind<<" "<<ind1<<" "<<ind2;
        
        if(ind1 != -1) return ind1;
        return ind2;
    }
};