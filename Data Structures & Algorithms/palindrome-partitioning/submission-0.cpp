class Solution {
public:
    vector<vector<string>> ans;

    void util(string s, int idx, vector<string> currlist) {
        if(idx >= s.size()) {
            ans.push_back(currlist);
            return;
        }

        string curr;

        // find substrs that create palindrome with curr idx ele and 
        // call util() for each

        // aabbaa idx=1 . endidx=n-1
        // a a b b a a
        // aa bb aa

        int j = idx;

        // standalone ele handled here
        while(j<s.size()) {
            int x=idx, y=j;
            while(x<=y && s[x] == s[y]) {
                x++;
                y--;
            }
            if(x>y) {
                curr = s.substr(idx, j-idx+1);
                currlist.push_back(curr);
                util(s, j+1, currlist);
                currlist.pop_back();
            }
            j++;
        }
    }

    vector<vector<string>> partition(string s) {
        // always start from 0 index
        vector<string> currlist;

        util(s, 0, currlist);

        return ans;
    }
};
