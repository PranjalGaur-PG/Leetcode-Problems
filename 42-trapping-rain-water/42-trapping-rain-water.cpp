class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> l(n,0), r(n,0);
        int mx;
        
        l[0] = 0; mx = height[0];
        for(int i=1;i<n;i++) {
            l[i] = mx;
            mx = max(mx, height[i]);
        } 
        
        r[n-1] = 0; mx = height[n-1];
        for(int i=n-1;i>=0;i--) {
            r[i] = mx;
            mx = max(mx, height[i]);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            int mn = min(r[i], l[i]);
            int water = mn - height[i];
            if(water > 0) ans += water;
        }
        return ans;
    }
};