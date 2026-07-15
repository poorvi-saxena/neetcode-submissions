

class Solution {
public:
    vector<vector<int>> ans;

    void util(vector<int>& nums, vector<bool> seen, vector<int> path) {
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(seen[i]) continue;
            if(i>0 && nums[i] == nums[i-1] && !seen[i-1]) continue;

            path.push_back(nums[i]);
            seen[i]=true;
            util(nums, seen, path);
            path.pop_back();
            seen[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n, false);
        vector<int> path;
        sort(nums.begin() , nums.end());

        util(nums, seen, path);

        return ans;
    }
};