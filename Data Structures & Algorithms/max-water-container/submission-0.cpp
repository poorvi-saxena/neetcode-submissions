
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0) return 0;

        int maxh = INT_MIN;
        int i=0, j=n-1;
        
        while(i<j) {
            maxh = max(maxh, min(heights[i], heights[j])*(j-i));
            if(heights[i] < heights[j]) i++;
            else j--;
        }

        return maxh;
    }
};
