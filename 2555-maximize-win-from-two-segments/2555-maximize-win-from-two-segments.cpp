class Solution {
public:
    int maximizeWin(vector<int>& arr, int k) {
        int ans = 0, n = arr.size();
        if(n==1) return 1;
        
        vector<int> fr(n, 0), bk(n, 0);
        int i=0, j=0, mx = 1;
        while(j<n) {
            while(j>=i && arr[j]-arr[i] > k) i++;
            mx = max(j-i+1, mx);
            fr[j] = mx;
            j++;
        }
        
        j=n-1, i=n-1, mx = 1;
        while(j>=0) {
            mx = max(i-j+1, mx);
            bk[j] = mx;
            while(j<=i && arr[i]-arr[j] > k) i--;
            // bk[j] = i-j+1;
            j--;
        }
        
        for(int i=0;i<n;i++) {
            // cout<<fr[i]<<" "<<bk[i]<<endl;
            if(fr[i]==1 && bk[i]==1) ans = max(ans, 2);
            else ans = max(ans, fr[i]+bk[i]-1);
        }
        // cout<<endl;
        return ans;
        
    }
};