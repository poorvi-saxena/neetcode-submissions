class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        int n = prices.size();
        int minp = prices[0];

        for(int i=1; i<n; i++) {
            if(prices[i] > minp) {
                ans = max(ans , prices[i]-minp);
            }
            minp = min(minp, prices[i]);
        }

        return ans == INT_MIN ? 0 : ans;
    }
};
