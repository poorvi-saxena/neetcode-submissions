class Solution {
public:

struct CompareSecond {
    bool operator()(pair<char,int>& a, pair<char,int>& b) {
        return a.second < b.second; 
    }
};

    string reorganizeString(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, CompareSecond> pq;
        unordered_map<char, int> mp;
        for(auto e:s) {
            mp[e]++;
        }

        for(auto e:mp) {
            pq.push({e.first, e.second});
        }

        string str = "";

        while(!pq.empty()) {
            char curr = pq.top().first;
            int freq = pq.top().second;
            pq.pop();
            int currn = str.size();
            if(str.size() > 0  && str[currn-1] == curr) {
                if(pq.empty()) return "";

                pair<char, int> hold = {curr, freq};

                curr = pq.top().first;
                freq = pq.top().second;
                pq.pop();
                pq.push(hold);
            } 
            str+=curr;
            freq--;
            if(freq > 0) {
                pq.push({curr, freq});
            } 
        }

        return str;
    }
};