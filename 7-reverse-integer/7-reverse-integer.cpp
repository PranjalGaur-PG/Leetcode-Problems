class Solution {
public:
    int reverse(int x) {
        int a = INT_MAX;
      int b = INT_MIN;

      int ans = 0;
      while(x != 0){
        if(a/10 < ans) return 0;
        if(b/10 > ans) return 0;
        ans = ans * 10 + x % 10;
        x = x / 10;
      }
      
      return ans;
    }
};