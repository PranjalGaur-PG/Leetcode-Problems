class Solution {
public:
    double hash(double f, double code[], string &word) {
		double result = 0.;
		for (auto &c : word) result = result * f + code[c];
		return result;
	}
	vector<int> findSubstring(string S, vector<string> &L) {
		uniform_real_distribution<double> unif(0., 1.);
		default_random_engine seed;
		double code[128];
		for (auto &d : code) d = unif(seed);
		double f = unif(seed) / 5. + 0.8;
		double value = 0;

		for (auto &str : L) value += log(hash(f, code, str));

    int unit = 1e9;
    int key = (value-floor(value))*unit;
    int nS = S.size(), nL = L.size(), nW = L[0].size();
    double fn = pow(f, nW-1.);
    vector<int> result;
    if (nS < nW) return result;
    vector<double> values(nS-nW+1);
    string word(S.begin(), S.begin()+nW);
    values[0] = hash(f, code, word);


    for (int i=1; i<=nS-nW; ++i) values[i] = (values[i-1] - code[S[i-1]]*fn)*f + code[S[i+nW-1]];


    for (int i=0; i<nW; ++i) {
        int j0=i, j1=i, k=0;
        double sum = 0.;

        while(j1<=nS-nW) {
            sum += log(values[j1]);
            ++k;
            j1 += nW;
            if (k==nL) {
                int key1 = (sum-floor(sum)) * unit;
                if (key1==key) result.push_back(j0);
                sum -= log(values[j0]);
                --k;
                j0 += nW;
            }
        }
    }
    return result;
}
};