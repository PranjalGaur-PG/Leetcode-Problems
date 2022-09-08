class Solution {
public:
    int mySqrt(int x) {
        long long i = 0, j = x, res = 0;
        
        while(i<=j) {
            long long mid = i+(j-i)/2;
            if(mid*mid == x) return mid;
            else if(mid*mid < x) {
                res = mid;
                i = mid+1;
            }
            else j = mid-1;
        }
        
        return res;
    }
};