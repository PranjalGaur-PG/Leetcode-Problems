class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int n = matrix.size()-1;
        int m = matrix[0].size()-1;
        int currentLimitX = 0;
        int currentLimitY = 0;
        int currentAdderX=1;
        int currentAdderY=0;
        int currentX = 0;
        int currentY = 0;
        while(true){
            answer.push_back(matrix[currentY][currentX]);
            
            if(currentX==m && currentAdderX==1){
                currentAdderX=0;
                currentAdderY=1;
                currentLimitY++;
            } else if(currentX==currentLimitX && currentAdderX==-1){
                currentAdderX=0;
                currentAdderY=-1;
                n--;
            } else if(currentY==n && currentAdderY==1){
                currentAdderX=-1;
                currentAdderY=0;
                m--;
            } else if(currentY==currentLimitY && currentAdderY==-1){
                currentAdderX=1;
                currentAdderY=0;
                currentLimitX++;
            }
            if(currentLimitX>m || currentLimitY>n){
                return answer;
            }
            currentX+=currentAdderX;
            currentY+=currentAdderY;

        }
        
        return answer;
    }
};