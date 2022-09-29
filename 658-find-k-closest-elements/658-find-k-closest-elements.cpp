class Solution {
public:
    int search(vector<int> a,int x) {
        int m,i,j,n=a.size();
        if(a[0]>x) return 0;
        if(a[n-1]<x) return n;
        
        i=0,j=n;
        while(i<j) {
            m = (i+j)/2;
            if(a[m] == x) return m;
            else if(a[m]>x) {
                if(m>0 && a[m-1]<x) return close(a,m-1,m,x);
                j = m;
            }
            else {
                if(m<n && a[m+1]>x) return close(a,m,m+1,x);
                i = m+1;
            }
        }
        return m;
    }
    int close(vector<int> arr,int a,int b,int x) {
        if(abs(arr[a]-x) <= abs(arr[b]-x)) return a;
        else return b;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int i,j,y,n=arr.size(),ind;
        ind = search(arr,x);
        
        if(ind == 0) {
            vector<int> ans(arr.begin(),arr.begin()+k);
            return ans;
        }
        else if(ind == n) {
            vector<int> ans(arr.begin()+n-k,arr.begin()+n);
            return ans;
        }
        
        i=ind-1; j=ind;
        while(k--) {
            if(i<0) j++;
            else if(j>=arr.size()) i--;
            else {
                if(abs(arr[i]-x) <= abs(arr[j]-x)) i--;
                else j++;
            }
        }
        
        vector<int> ans;
        for(y=i+1;y<j;y++) ans.push_back(arr[y]);
        return ans;
    }
};