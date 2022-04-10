class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        
        vector<int> arr(100007, 0);
        int mx = INT_MIN;
        for(auto it : nums) {
            arr[it]++;
            mx = max(it, mx);
        }
        
        int ans=0;
        for(int i=0;i<=mx;i++) {
            if(arr[i]>1) {
                ans += (arr[i]-1);
                arr[i+1] += arr[i] - 1;
            }
        }
        
        int val = arr[mx+1] - 1;
        val = ((val * (val+1)) / 2) ;
        return ans + val;
        // return ans;
    }
};