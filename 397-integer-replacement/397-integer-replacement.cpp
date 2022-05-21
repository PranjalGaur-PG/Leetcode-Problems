#define ll long long
class Solution {
public:
    ll fun(ll n) {
        if(n==1) return 0;
        
        if(n%2) return (1 + min( fun(n+1), fun(n-1) ) );
        else return (1 + fun(n/2));
    }
        
    int integerReplacement(int n) {
        ll t = n;
        ll ans = fun(t);
        return (int)ans;
    }
};