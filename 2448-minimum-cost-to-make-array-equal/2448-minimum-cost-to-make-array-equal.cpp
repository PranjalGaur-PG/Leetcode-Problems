class Solution {
public:
    using ll=long long;
    
    long long sol(vector<int>& nums, vector<int>& cost, int mid){
        long long s = 0;
        
        for(int i =0;i<nums.size();i++){
            long long k = abs(nums[i]-mid);
            s += k*cost[i];  
        }   
        return s;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l = 1, h = 1e6;
        // for(auto it : nums) {
        //     l = min(l, it);
        //     h = max(h, it);
        // }
        
        while(l <= h) {
            int mid = (l+h)/2;
            ll s1 = sol(nums, cost, mid);
            if(l == h) return s1;
            
            ll s2 = sol(nums, cost, mid-1);
            ll s3 = sol(nums, cost, mid+1);
            
            if(s2 >= s1 && s1 <= s3) return s1; 
            if(s2 < s1){
                h = mid;
                continue;
            } 
            if(s3 < s1){
                l = mid;
            }
        }
        
        return 0;
    }
};