class Solution {
public:
    bool find132pattern(vector<int>& nums) {
//         int n=nums.size();
//         if(n<3) return false;
        
//         vector<int> mn(n), mx(n);
//         int t=nums[0];
//         mn[0] = t;
//         for(int i=1;i<n-1;i++) {
//             mn[i] = t;
//             t = min(t, nums[i]);
//         }
        
//         mx[n-1] = nums[n-1];
//         t = mx[n-1];
//         for(int i=n-2;i>0;i--) {
//             mx[i] = t;
//             t = max(t, nums[i]);
//         }
        
//         for(int i=1;i<n-1;i++) {
//             if(nums[i] > mn[i] && nums[i] > mx[i] && mx[i]>mn[i]) return true;
//         }
        
//         return false;
        stack<int> s;
        int prev = INT_MIN;
        
        for (auto it = nums.rbegin(); it != nums.rend(); it++) {
            while (!s.empty() && s.top() < *it) {
                if (prev > s.top())
                    return true;
                prev = s.top();
                s.pop();
            }
            
            s.push(*it);
        }
        
        return !s.empty() && prev > s.top();
    }
};