class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         unordered_set<int> st(nums.begin() , nums.end());
         vector<int> listn;
         int maxlen = 0;

         for(int i=0; i<nums.size(); i++) {
            if(st.find(nums[i] - 1) == st.end()) {
                listn.push_back(nums[i]);
            }
         }

         for(int i:listn) {
            int len = 1;
            int x = i+1;

            while(st.find(x)!=st.end()) {
                len++;
                x++;
            }
            maxlen = max(len, maxlen);
         }

         return maxlen;
    }
};
