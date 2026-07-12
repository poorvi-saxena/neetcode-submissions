class Solution {
public:
    vector<vector<int>> ans;

    void calculate(vector<int>& nums, int idx, vector<int> currlist) {
        int n = nums.size();
        if(idx == n) {
            ans.push_back(currlist);
            return;
        }

        // for(int i=idx+1; i<n; i++) {
            calculate(nums, idx+1, currlist);
            currlist.push_back(nums[idx]);
            calculate(nums, idx+1, currlist);
            
        // }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currlist;
        calculate(nums, 0, currlist);
        return ans;
    }
};
