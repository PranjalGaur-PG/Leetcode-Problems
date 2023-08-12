class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();
        bool one;
        
        while(i<n) {
            if(bits[i]) {
                i++;
                one = true;
            }
            else one = false;
            i++;
        }
        
        return !one;
    }
};