class Solution {
public:
    int ans;
//     void merge(vector<int>& nums, int l, int m, int h) {
//         vector<int> temp;
//         int left = l, right = m+1;
        
//         while(left <= m && right <= h) {
//             if(nums[left] <= nums[right]) {
//                 temp.push_back(nums[left]);
//                 left++;
//             }
//             else {
//                 temp.push_back(nums[right]);
//                 ans += (m-left+1);
//                 right++;
//             }
//         }
        
//         while(left <= m) {
//             temp.push_back(nums[left]);
//             left++;
//         }
//         while(right <= h) {
//             temp.push_back(nums[right]);
//             right++;
//         }
        
//         for(int i=l;i<=h;i++) nums[i] = temp[i-l];
        
//     }
    void merge(vector<int>&nums,int low,int mid,int high)
    {
        int i=low;
        int j=mid+1;
        
       
        
        while(i<=mid and j<=high)
        {
            if(nums[i]>2*1ll*nums[j])
            {
                ans+=(mid-i+1);
                j++;
            }
            else
            {
                i++;
            }
        }
		// This may take upto nlogn time in worst case
        sort(nums.begin()+low,nums.begin()+high+1);
    }
        
    void rec(vector<int>& nums, int l, int h) {
        if(l>=h) return;
        
        int m = (l+h)/2;
        rec(nums, l, m);
        rec(nums, m+1, h);
        
        merge(nums, l, m, h);
    }
        
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        ans = 0;
        rec(nums, 0, n-1);
        
        return ans;
    }
};