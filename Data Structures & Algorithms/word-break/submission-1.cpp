class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        unordered_set<string> st(wordDict.begin() , wordDict.end());
        string curr = "";

        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                curr = s.substr(j, i-j+1);

                if(st.find(curr) != st.end()) {
                    if(dp[j]) {
                        dp[i+1] = true;
                    }  
                } 
            }
            
        }
        return dp[n];
    }
};
