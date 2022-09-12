class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int score=0,maxScore=0;
        int n=tokens.size();
        
        sort(tokens.begin(),tokens.end()); // sort tokens
        
        for(int i=0,j=n-1;i<=j; )
        {
            if(tokens[i]<=power)    // can play face up
            {
                score++;
                power-=tokens[i];          // decrease power by min token
                maxScore=max(score,maxScore); // update maxScore
               i++;
            }
            else if(score>=1)      // can play face down
            {
                power+=tokens[j];    // increase power by max token
                score--;
                j--;
            }
            else                        // none of above possible
                break;
            
        }
        return maxScore;
    }
};