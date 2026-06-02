class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m1;

        for(int i=0; i<nums.size(); i++) {
            m1[nums[i]]++;

            unordered_map<int, int> m2;
            if(m1.size() > 2) {

                for(auto ele:m1) {
                    if(ele.second > 1)
                        m2[ele.first] = ele.second-1;
                }
                m1 = m2;
            }

            
        }
        vector<int> res;

        for(auto ele:m1) {
            int freq = 0;
            for(auto num:nums) if(num==ele.first) freq++;
            if(freq > nums.size()/3) res.push_back(ele.first);
        }

        return res;
    }
};