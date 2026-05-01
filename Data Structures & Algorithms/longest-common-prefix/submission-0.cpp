class Solution {
public:
    string compare(string a, string b) {
        int i=0; 
        if(a=="" || b=="") return "";

        while(i < min((int)a.size(), (int)b.size())) {
            if(a[i] == b[i]) i++;
            else {
                if(i==0) return "";
                else return a.substr(0, i);
            }
        }
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string longest = strs[0];

        for(int i=1; i<n; i++) {
            longest = compare(longest, strs[i]);
        }

        return longest;
    }
};