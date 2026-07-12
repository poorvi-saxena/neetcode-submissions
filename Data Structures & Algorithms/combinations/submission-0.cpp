class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, int n, int k, vector<int> curr) {
        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for(int i=idx+1; i<=n; i++) {
            curr.push_back(i);
            solve(i, n, k, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(0, n, k, curr);
        return ans;
    }
};