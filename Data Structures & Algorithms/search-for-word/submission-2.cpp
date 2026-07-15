


class Solution {
public:
    bool check(vector<vector<char>>& board, string word, int x, int y, int k, vector<vector<bool>>& seen) {
        if(k>=word.size()) return true;
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] != word[k]) return false;
        if(seen[x][y]) return false;
        seen[x][y]=true;
        if(check(board, word, x+1, y, k+1, seen) || check(board, word, x-1, y, k+1, seen) || check(board, word, x, y+1, k+1, seen) || check(board, word, x, y-1, k+1, seen)) return true;
        seen[x][y]=false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        queue<pair<int, int>> q;
        int m = board.size() , n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0]) q.push({i,j});
            }
        }

        while(!q.empty()) {
            int i = q.front().first , j = q.front().second;
            q.pop();
            vector<vector<bool>> seen(m, vector<bool>(n, false));
            if(check(board, word, i, j, 0, seen)) return true;
        }

        return false;
    }
};
