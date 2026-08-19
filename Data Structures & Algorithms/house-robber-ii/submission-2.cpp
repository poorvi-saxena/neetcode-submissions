class Solution {
public:
    int robbed(vector<int>& nums, int start) {
        int availableN = nums.size()-1;
        if(availableN == 1) return nums[start];
        if(availableN == 0) return 0;

        vector<int> dp(availableN, 0);
        
        dp[0] = nums[start];
        dp[1] = max(nums[start] , nums[start+1]);
        cout<<availableN<<" ";
        for(int i=start+2; i<start+availableN; i++) {
            dp[i-start] = max((dp[i-start-2] + nums[i]) , dp[i-start-1]);
        }

        return max(dp[availableN-2] , dp[availableN-1]);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        return max(robbed(nums, 0) , robbed(nums, 1));
    }
};
