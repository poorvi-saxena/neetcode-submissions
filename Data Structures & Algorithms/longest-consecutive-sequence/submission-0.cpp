class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLong = 0;

        for(int i:nums){
            if(st.find(i-1) == st.end()){
                int len=1;
                while(st.find(i+len) != st.end()){
                    len++;
                }
                maxLong = max(maxLong, len);
            }
        }
        return maxLong;
    }
};
