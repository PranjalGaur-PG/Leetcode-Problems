class Solution {
     int getMaxGap( vector<int>& base, int maxSize) {
            // support variables
            int res = 0, prev = 0;
            base.push_back(maxSize);
            sort(begin(base), end(base));
            // finding the maximum gap
            for (int n: base) res = max(res, n - prev), prev = n;
            return res;
        }
    public:
        int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
            return (long)getMaxGap(hc, h) * getMaxGap(vc, w) % 1000000007;
        }
};