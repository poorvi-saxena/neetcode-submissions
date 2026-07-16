

// ["((()))","((()())","((()()()","(()(())","(()(()()"]

// Expected output:
// ["((()))","(()())","(())()","()(())","()()()"]

class Solution {
public:
    vector<string> ans;
    void util(int open, int close, string str) {
        if(close == 0) {
            ans.push_back(str);
            return;
        }
        if(open > 0) {
            str+="(";
            util(open-1, close, str);
            str = str.substr(0, str.size()-1);
        }

        if(open < close) {    
            str+=")";
            util(open, close-1, str);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        if(n==0) return {};
        
        int open = n, close = n;

        util(open, close, "");
        return ans;
    }
};
