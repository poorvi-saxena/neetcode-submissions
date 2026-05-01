class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        
        // if(edges.size() < n-1) return 0;
        
        int count = 0;

        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0; i<n; i++){
            if(!vis[i]) {
                count++;
                dfs(adj, vis, i);
            }
        }

        return count;
    }

private: 
    void dfs(vector<vector<int>> adj, vector<bool>  &vis, int i){
        if(vis[i]) return;

        vis[i] = true;

        for(auto ele:adj[i]){
            if(!vis[ele]) {
                dfs(adj, vis, ele);
            }
        }
    }
};




