class Solution {
public:
    bool solve(vector<int>& wei, int days, int mid) {
        int n = wei.size();
        int cnt = 1, sum = 0;
        
        for(int i=0;i<n;i++) {
            if(wei[i]>mid) return false;
            sum += wei[i];
            
            if(sum>mid) {
                cnt++;
                sum = wei[i];
            } 
            
            if(cnt>days) return false;
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int s=0, mx=0;
        for(auto it : weights) {
            s += it;
            mx = max(mx, it);
        }
        
        int i=mx, j=s, res=-1;
        while(i<=j) {
            int mid = i + (j-i)/2;
            if(solve(weights, days, mid)) {
                res = mid;
                j = mid-1;
            }
            else i = mid+1;
        }
        
        return res;
    }
};