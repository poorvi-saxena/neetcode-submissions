class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        unordered_map<char, unordered_set<char>> mp;
        vector<int> count(26, -1);

        for(auto &word : words) {
            for(char c : word) {
                if(count[c-'a'] == -1)
                    count[c-'a'] = 0;
            }
        }

        for(int i = 0; i < words.size()-1; i++) {

            string curr = words[i];
            string nextw = words[i+1];

            int n = min(curr.size(), nextw.size());

            int j = 0;

            while(j < n) {

                if(curr[j] != nextw[j]) {

                    if(mp[curr[j]].find(nextw[j]) == mp[curr[j]].end()) {

                        mp[curr[j]].insert(nextw[j]);
                        count[nextw[j]-'a']++;
                    }

                    break;
                }

                j++;
            }

            if(j == n && curr.size() > nextw.size())
                return "";
        }

        queue<char> q;

        for(int i=0; i<26; i++) {
            if(count[i] == 0)
                q.push(i + 'a');
        }

        string s = "";

        while(!q.empty()) {

            char ele = q.front();
            q.pop();

            s += ele;

            for(auto e : mp[ele]) {

                count[e-'a']--;

                if(count[e-'a'] == 0)
                    q.push(e);
            }
        }

        int totalChars = 0;

        for(int i=0; i<26; i++) {
            if(count[i] != -1)
                totalChars++;
        }

        if(s.size() != totalChars)
            return "";

        return s;
    }
};