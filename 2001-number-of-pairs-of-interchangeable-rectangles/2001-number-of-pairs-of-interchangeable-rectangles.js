/**
 * @param {number[][]} rectangles
 * @return {number}
 */
var interchangeableRectangles = function(rectangles) {
    let ans = 0;
    let count = {};
    
    for(let num of rectangles) {
        if(count[num[0]/num[1]]) {
            ans += count[num[0]/num[1]];
            count[num[0]/num[1]]++;
        }
        else count[num[0]/num[1]] = 1;
    }
    
    return ans;
};