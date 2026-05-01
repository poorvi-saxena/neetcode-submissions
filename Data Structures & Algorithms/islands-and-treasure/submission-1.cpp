class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int i = ele.first;
            int j = ele.second;

            if(i+1 < m && grid[i+1][j] != -1 && grid[i+1][j] > grid[i][j]){
                grid[i+1][j] = grid[i][j] + 1;
                q.push({i+1, j});
            }
            if(i-1 >= 0 && grid[i-1][j] != -1 && grid[i-1][j] > grid[i][j]){
                grid[i-1][j] = grid[i][j] + 1;
                q.push({i-1, j});
            }
            if(j+1 < n && grid[i][j+1] != -1 && grid[i][j+1] > grid[i][j]){
                grid[i][j+1] = grid[i][j] + 1;
                q.push({i, j+1});
            }
            if(j-1 >= 0 && grid[i][j-1] != -1 && grid[i][j-1] > grid[i][j]){
                grid[i][j-1] = grid[i][j] + 1;
                q.push({i, j-1});
            }
        }
    }
};
