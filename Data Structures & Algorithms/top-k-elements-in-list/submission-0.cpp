class Solution {
public:struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            // Min-heap: elements with smaller frequencies float to the top
            return a.second < b.second; 
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        vector<int> ans;

        for(auto ele:nums) {
            mp[ele]++;
        }

        for(auto ele:mp) {
            pq.push({ele.first, ele.second});
        }

        while(k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};
