

class Solution {
public:

struct CompareSecond {
    bool operator()(pair<char,int>& a, pair<char,int>& b) {
        return a.second < b.second; 
    }
};

    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, CompareSecond> pq;

        if(a>0) pq.push({'a', a});
        if(b>0) pq.push({'b', b});
        if(c>0) pq.push({'c', c});

        string str = "";

        while(!pq.empty()) {
            char curr = pq.top().first;
            int freq = pq.top().second;
            pq.pop();
            int currn = str.size();
            if(str.size() >1  && str[currn-2] == curr && str[currn-1] == curr) {
                if(pq.empty()) return str;

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