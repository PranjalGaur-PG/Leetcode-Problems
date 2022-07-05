class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        sort(a.begin(),a.end());
        int i,j,n=a.size(),c=1,m=0;
        if(n==0 || n==1) return n;
        for(i=1;i<n;i++) {
            if(a[i]==a[i-1] ) continue;
            if(a[i]==a[i-1]+1) c++;
            else {
                m= max(c,m);
                c=1;
            }
        }
        m = max(c,m);
        return m;
    }
};