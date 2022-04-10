class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        
        vector<int> arr(100007, 0);
        for(auto it : nums) arr[it]++;
        
        int ans=0;
        for(int i=0;i<100003;i++) {
            if(arr[i]>1) {
                ans += (arr[i]-1);
                arr[i+1] += arr[i] - 1;
            }
        }
        
        int val = arr[100003] - 1;
        val = ((val * (val+1)) / 2) ;
        return ans + val;
        // return ans;
    }
};