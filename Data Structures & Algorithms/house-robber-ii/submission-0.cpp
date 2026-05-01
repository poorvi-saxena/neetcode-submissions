class Solution {
    int getMaxTheft(vector<int>& nums, int start, int end){
        if(start==end) return 0;
        int n = end-start;
        if(n==1) return nums[start];
        vector<int> dp(n);

        dp[0] = nums[start];
        dp[1] = max(nums[start+1], nums[start]);

        for(int i=2; i<n; ++i){
            dp[i] = max(dp[i-2]+nums[i+start], dp[i-1]);
        }
        return dp[n-1];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        int firstHouse = getMaxTheft(nums, 0, n-1);
        int lastHouse = getMaxTheft(nums, 1, n);
        return max(firstHouse, lastHouse);
    }
};
