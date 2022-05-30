class Solution {
public:
//     int divide(int dividend, int divisor) {
//         if(dividend == 1<<31 && divisor==-1) return INT_MAX;
        
//         bool sign = ((dividend>=0) == (divisor>=0)) ? true : false;
//         dividend = abs(dividend);
//         divisor = abs(divisor);
        
//         int res = 0;
//         while(dividend - divisor >= 0) {
//             int cnt = 0;
//             while(dividend - (divisor << 1 <<cnt) > 0) cnt++;
//             res += (1<<cnt);
//             dividend -= divisor<<cnt;
//         }
        
//         if(sign) return res;
//         return -res;
//     }
    int divide(int dividend, int divisor) {
        // if (A == INT_MIN && B == -1) return INT_MAX;
        // int a = abs(A), b = abs(B), res = 0, x = 0;
        // while (a - b >= 0) {
        //     for (x = 0; a - (b << x << 1) >= 0; x++);
        //     res += 1 << x;
        //     a -= b << x;
        // }
        // return (A > 0) == (B > 0) ? res : -res;
         if(dividend==INT_MIN && divisor == -1) return INT_MAX;
        bool sign = dividend>=0 == divisor>=0;
        long divid = labs(dividend) , divi = labs(divisor) , result = 0;
        while(divid - divi>=0){
            int cnt=0;
            while( divid - (divi<<1<<cnt)>=0)
                cnt++;
            result+=1<<cnt;
            divid -= divi<<cnt;
        }
        return sign?result:-result;
    }
};