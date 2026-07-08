class Solution {
public:
    vector<vector<int>> ans;

    void recUtil(vector<int>& nums, int target, int idx, vector<int> curr) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        int n = nums.size();
        if(idx >= n) return;

        for(int i=idx+1; i<nums.size(); i++) {
            if(i>idx+1 && nums[i] == nums[i-1]) continue;
            if(target-nums[i] >= 0) {
                curr.push_back(nums[i]);
                recUtil(nums,target-nums[i],i,curr);
                curr.pop_back();
            } else {
                break;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        if(nums.size() == 0) return {};
        sort(nums.begin(), nums.end());

        // for(int i=0; i<nums.size(); i++) {
            recUtil(nums, target, -1, {});
        // }
        

        return ans;
    }
};
