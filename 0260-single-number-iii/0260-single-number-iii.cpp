class Solution {
public:
    int most_significant_bit(long long n) {
        int mask = 1;
        while(1) {
            if((mask & n) == 0) {
                mask = mask << 1;
            }
            else break;
        }
        return mask;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int first_xor = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
            first_xor = first_xor ^ nums[i];
        int set_bit = most_significant_bit(first_xor);
        int xor_a = 0, xor_b = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] & set_bit) 
                xor_a ^= nums[i];
            else 
                xor_b ^= nums[i];
        }
        return {xor_a,xor_b};
    }
};