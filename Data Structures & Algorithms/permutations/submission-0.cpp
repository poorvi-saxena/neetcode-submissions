class Solution {
public:
    int n;
    vector<vector<int>> ans;

    void util(vector<int>& nums, vector<int> curr, int idx, unordered_set<int>st) {
        st.insert(idx);
        curr.push_back(nums[idx]);

        if(st.size() == n || curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for(int i=0; i<n; i++) {
            if(st.find(i) == st.end()) {
                util(nums, curr, i, st);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();

        for(int i=0; i<n; i++) {
            unordered_set<int> st;
            util(nums, {}, i, st);
        }

        return ans;
    }
};
