class Solution {
public:        
    vector<vector<string>> ans;

    bool checkEligibility(vector<string>& tempans, int idx, int level) {
        // check all verticals cells
        for(int i=0; i<level; i++) {
            if(tempans[i][idx] == 'Q') return false;
        }
        int n = tempans.size();

        // diagonally left
        int x=level-1, yx=idx-1, yy=idx+1;
        while(x>=0 && (yx>=0 || yy<n)) {
            if(tempans[x][yx] == 'Q' || tempans[x][yy] == 'Q') return false;
            x--;
            yx--;
            yy++;
        }

        return true;
    }

    void dfs(int level, vector<string>& tempans) {
        int n = tempans.size();
        if(level >= n) {
            ans.push_back(tempans);
            return;
        }

        for(int i=0; i<n; i++) {
            // place queen at [level][i] ans check eligibility if yes send forward
            if(checkEligibility(tempans, i, level)) {
                tempans[level][i] = 'Q';
                dfs(level+1, tempans);
                tempans[level][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string temp(n, '.');
        vector<string> tempans(n, temp);

        for(int i=0; i<n; i++) {
            tempans[0][i] = 'Q';
            dfs(1, tempans);
            tempans[0][i] = '.';
        }

        return ans;
    }
};
