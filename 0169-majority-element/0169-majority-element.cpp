class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=-1, cnt = 0;
        
        for(auto it : nums) {
            if(it != ele) {
                if(!cnt) ele = it, cnt = cnt+1;
                else cnt--;
            }
            else cnt++;
        }
        
        return ele;
    }
};