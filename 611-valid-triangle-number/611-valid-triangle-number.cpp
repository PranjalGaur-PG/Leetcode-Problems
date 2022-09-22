class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int cnt = 0;
        for(int x = n-1;x>1;x--) {
            int i = 0, j = x-1;
            
            while(i<j) {
                if(nums[i]+nums[j] > nums[x]) {
                    cnt += (j-i);
                    j--;
                }
                else i++;
            }
        }
        
        return cnt;
    }
};