class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int left = 0, ret = 0, numT = 0, numF = 0;

        for (int right = 0; right < n; right++) {
            if (answerKey[right] == 'T') {
                numT++;
            } else {
                numF++;
            }

            while (numT > k && numF > k) {
                if (answerKey[left] == 'T') {
                    numT--;
                } else {
                    numF--;
                }
                left++;
            }

            ret = max(ret, right - left + 1);
        }

        return ret;
    }
};