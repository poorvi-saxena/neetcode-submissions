class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        vector<int> sz;

        for(auto ele:strs) {
            sz.push_back(ele.size());
        }

        for(int i=0; i<sz.size(); i++) {
            res+=to_string(sz[i]);
            if(i<sz.size()-1) {
                res+=",";
            }
        }
        res+="#";

        for(auto ele:strs){
            res+=ele;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<int>sz;
        int i=0, n=s.size(), startidx=-1;
        string curr="";

        vector<string> res;

        while(i<n) {
            if(s[i] == '#') {
                startidx = i+1;
                break;
            }
            if(s[i] == ',') {
                sz.push_back(stoi(curr));
                curr="";
            } else {
                curr+=s[i];
            }
            i++;
        }
        if(curr.size() > 0) sz.push_back(stoi(curr));

        if(startidx == -1) {

        }

        int j = 0, jn = sz.size();

        for(int j=0; j<jn; j++) {
            res.push_back(s.substr(startidx, sz[j]));
            startidx+=sz[j];
        }

        return res;
    }
};
