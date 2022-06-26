class Solution {
public:
    string inv(string s) {
        string ans;
        for(int i=0;i<s.size();i++) ans += (s[i] == '1' ? '0' : '1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string fun(int n) {
        if(n==1) return "0";
        
        string temp1 = fun(n-1);
        string temp2 = inv(temp1);
        
        string ans = temp1 + "1" + temp2;
        // cout<<n<<" "<<ans<<endl;
        return ans;
    }
    
    char findKthBit(int n, int k) {
        string ans = fun(n);
        
        return ans[k-1];
    }
};