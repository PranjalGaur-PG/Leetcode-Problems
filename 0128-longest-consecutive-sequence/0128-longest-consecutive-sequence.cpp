class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        unordered_set<int> record(num.begin(),num.end());
        if(num.size()==0) return 0;
        int res = 1;
        for(int n : num){
            if(record.find(n)==record.end()) continue;
            record.erase(n);
            int prev = n-1,next = n+1;
            while(record.find(prev)!=record.end()) record.erase(prev--);
            while(record.find(next)!=record.end()) record.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }
};