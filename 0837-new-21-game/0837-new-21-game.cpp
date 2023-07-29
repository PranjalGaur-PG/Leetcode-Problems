class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0 || W == 1) return 1.0;
        double res = 0;
        double sum = 1.0;
        queue<double> q;
        for(int i = 1; i < W; i++) q.push(0);
        q.push(1.0);
        for(int i = 1; i < K; i++) {
            q.push(sum / W);
            sum += sum / W;
            if(q.size() > W) {
                sum -= q.front();
                q.pop();
            }
        }
        for(int i = K; i <= N && q.size(); i++) {
            res += sum / W;
            sum -= q.front();
            q.pop();
        }
        return res;
    }
};