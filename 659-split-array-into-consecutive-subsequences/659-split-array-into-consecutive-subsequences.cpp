class Solution {
public:
    bool isPossible(vector<int>& nums) {
         unordered_map<int, int> freq, end;
        for(auto i:nums)freq[i]++;
        for(auto i:nums){
            if( freq[i] <= 0)continue;
            if(end[i-1] > 0){
                end[i-1]--;
                freq[i]--;
                end[i]++;
            }
            else if( freq[i+1] and  freq[i+2] ){
                freq[i]--;
                freq[i+1]--;
                freq[i+2]--;
                end[i+2]++;
            }
            else return false;
        }
        return true;
    }
};