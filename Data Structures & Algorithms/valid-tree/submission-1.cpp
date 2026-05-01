
class Solution {
    bool dfs(vector<vector<int>> adjList, int i, unordered_set<int> &vis, int parent){
        if(vis.count(i)) return false;
      
        vis.insert(i);

        for(auto ele:adjList[i]) {
            if(ele == parent) continue;
           if(!dfs(adjList, ele, vis, i)) return false;
        }

        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }
        unordered_set<int> vis;
        vector<vector<int>> adjList(n);

        for(auto &edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        if(!dfs(adjList, 0, vis, -1)){
            return false;
        }

        return vis.size() == n;
    }
};

