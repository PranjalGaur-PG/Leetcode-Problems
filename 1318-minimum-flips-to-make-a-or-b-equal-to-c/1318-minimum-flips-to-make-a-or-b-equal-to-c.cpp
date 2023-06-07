class Solution {
public:
    bool isSet(int n, int k) {
        if (n & (1 << k)) return true;
        return false;
    }
    int minFlips(int a, int b, int c) {
        vector<vector<int>> bts(3, vector<int> (32, 0));
        int cnt = 0;
        bool x, y, z;
        
        for(int i=0;i<32;i++) {
            x = isSet(a, i);
            y = isSet(b, i);
            z = isSet(c, i);
            
            if(!z) cnt += (x+y);
            else if(x+y == 0) cnt++;
            // cout<<(1<<i)<<" "<<x<<" "<<y<<" "<<z<<endl;
        }
        
        return cnt;
    }
};