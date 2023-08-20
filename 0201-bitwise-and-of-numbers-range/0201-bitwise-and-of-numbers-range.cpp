class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(!left) return 0;
        int x = log2(left), y = log2(right);
        
        if(x != y) return 0; 
        
        int res = left;
        for (long i = left; i <= right; i++)
            res &= i;
                
        return res;
    }
};