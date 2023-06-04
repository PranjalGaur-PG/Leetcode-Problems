class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3, 0);
        
        for(auto it : nums) cnt[it]++;
        
        for(int i=0;i<nums.size();i++) {
            if(cnt[0]) nums[i] = 0, cnt[0] = cnt[0]-1;
            else if(cnt[1]) nums[i] = 1, cnt[1] = cnt[1]-1;
            else nums[i] = 2, cnt[2] = cnt[2]-1;
        }
    }
};