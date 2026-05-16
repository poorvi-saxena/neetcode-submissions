class Solution {
public:
    int count;
    void checkValidity(int idx, int sum, vector<int>& nums, int k) {
        if(idx >= nums.size()) return;

        sum+=nums[idx];
        if(sum == k) count++;
        checkValidity(idx+1, sum, nums, k);
    }

    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        count=0;

        for(int i=0; i<n; i++) {
            if(nums[i] == k) count++;
            int sum = nums[i];
            checkValidity(i+1, sum, nums, k);
        }

        return count;
    }
};
