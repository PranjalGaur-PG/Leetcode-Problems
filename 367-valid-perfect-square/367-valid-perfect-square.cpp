typedef long long ll;
class Solution {
public:
    bool isPerfectSquare(int num) {
        ll i = 0, j = num, val = num;
        while(i<=j) {
            ll mid = (i+j)/2;
            if(mid*mid == val) return true;
            else if(mid*mid < val) i = mid+1;
            else j = mid-1;
        }
        
        return false;
    }
};