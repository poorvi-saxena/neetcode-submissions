


class Solution {
public:
    vector<vector<int>> ans;
    void recUtil(vector<int>& nums, vector<int> currList, int idx, int target) {
        int n = nums.size();

        if(target == 0) {
            ans.push_back(currList);
            return;
        }

        for(int i=idx; i<n; i++) {
            if(target-nums[i] >= 0) {
                currList.push_back(nums[i]);
                recUtil(nums, currList,i, target-nums[i]);
                currList.pop_back();
            } else {
                break;
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        if(nums.size() == 0) return {};
        sort(nums.begin() , nums.end());
        recUtil(nums, {}, 0, target);

        return ans;
    }
};
