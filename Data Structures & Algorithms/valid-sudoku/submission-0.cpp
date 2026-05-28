class Solution {
public:
    bool isCellValid(vector<vector<char>>& board, int x, int y) {
        int m = board.size();
        int n = board.size();
        int ri = (x/3)*3;
        int ci = (y/3)*3;

        // check grid
        for(int i=ri; i<ri+3; i++) {
            for(int j=ci; j<ci+3; j++) {
                if(i!=x && j!=y && board[i][j] == board[x][y]) return false;
            }
        }

        for(int i=0; i<m; i++) {
            if(i!=x && board[i][y] == board[x][y]) return false;
        }

        for(int i=0; i<n; i++) {
            if(i!=y && board[x][i] == board[x][y]) return false;
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board.size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] != '.') {
                    if(!isCellValid(board, i, j)) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
