class Solution {
public:
    static bool comp(int a, int b) {
        string s1 = to_string(a), s2=to_string(b);
        return s1+s2 > s2+s1;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        
        string ans;
        for(auto it : nums) ans += to_string(it);
        if(nums[0]==0) return "0";
        
        return ans;
    }
};