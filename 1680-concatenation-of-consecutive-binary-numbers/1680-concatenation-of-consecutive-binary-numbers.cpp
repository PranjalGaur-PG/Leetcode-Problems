class Solution {
public:
    int getBinary(int n) {
        int count = 0;
        while(n > 0) {
            n = n / 2;
            count++;
        }
        return count;
    }
    int concatenatedBinary(int n) {
        long long ans = 1;
        int mod = 1e9 + 7;
        for(int i = 2; i <= n; i++) {
            int  bits = getBinary(i);
            ans = ((ans << bits) % mod + i) % mod;
        }
        return (int)ans;
    }
};