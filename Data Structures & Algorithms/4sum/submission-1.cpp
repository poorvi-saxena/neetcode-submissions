class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i=0; i<n-3; i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<n-2; j++) {
                if(j>i+1 && nums[j] == nums[j-1]) continue;

                int a = j+1, b = n-1;
                while(a<b) {
                    long long sum = 1LL*nums[i] + nums[j] + nums[a] + nums[b];

                    if(sum==target) {
                        ans.push_back({nums[i] , nums[j] , nums[a] , nums[b]});
                        a++;
                        b--;

                        while(a<b && nums[a] == nums[a-1]) a++;
                        while(a<b && nums[b] == nums[b+1]) b--;
                    } else if(sum < target) a++;
                    else b--;
                }
            }

        }
            return ans;
    }
};