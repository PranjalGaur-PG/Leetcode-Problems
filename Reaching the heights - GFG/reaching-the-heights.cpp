// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    sort(a,a+n,greater<int>());
    
    vector<int>v;
    if(n==1) {
       v.push_back(a[0]);
       return v;
    }
    
    if(a[0]-a[n-1]==0) {
       v.push_back(-1);
       return v;
    }
    
    int i,j;
    for( i=0,j=n-1;i<j;i++,j--) {
       v.push_back(a[i]);
       v.push_back(a[j]);
    }
    
    if(n%2!=0) v.push_back(a[i]);
    
    return v;
}
