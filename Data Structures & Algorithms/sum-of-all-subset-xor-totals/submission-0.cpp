

class Solution {
public:
    int ans;
    void util(vector<int>& nums, int idx, int val) {
        if(idx==nums.size()) {
            ans+=val;
            return;
        }

        
            util(nums, idx+1, val^nums[idx]);
            util(nums, idx+1, val);
        
    }

    int subsetXORSum(vector<int>& nums) {
        ans = 0;
        util(nums, 0, 0);
        return ans;
    }
};