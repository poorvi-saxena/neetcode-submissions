class Solution {
public:
    void findLand(vector<vector<int>>& grid, int i, int j, int distance){
        int m = grid.size();
        int n = grid[0].size();

        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == -1){
            return;
        }

        if(grid[i][j] < distance){
            return;
        }

        grid[i][j] = distance;
        
        findLand(grid, i+1, j, distance+1);
        findLand(grid, i, j+1, distance+1);
        findLand(grid, i-1, j, distance+1);
        findLand(grid, i, j-1, distance+1);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    findLand(grid, i+1, j, 1);
                    findLand(grid, i, j+1, 1);
                    findLand(grid, i-1, j, 1);
                    findLand(grid, i, j-1, 1);
                }
            }
        }

    }
};
