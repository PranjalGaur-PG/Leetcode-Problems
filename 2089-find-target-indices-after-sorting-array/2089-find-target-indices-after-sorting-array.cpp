class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        int i=0, j=nums.size()-1, st=-1, en=-1;
        while(i<=j) {
            int mid = (i+j)/2;
            if(nums[mid]==target) {
                st = mid;
                j = mid-1;
            }
            else if(nums[mid] > target) j = mid-1;
            else i = mid+1;
        }
        
        if(st == -1) return ans;
        
        i=0, j=nums.size()-1;
        while(i<=j) {
            int mid = (i+j)/2;
            if(nums[mid]==target) {
                en = mid;
                i = mid+1;
            }
            else if(nums[mid] > target) j = mid-1;
            else i = mid+1;
        }
        
        cout<<st<<" "<<en;
        
        for(int x=st;x<=en;x++) ans.push_back(x);
        
        return ans;
    }
};