class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int v, int parent, vector<int> adj[], vector<int> &visited) {
        visited[v] = 1;
        for(auto &neigh: adj[v]) {
            if(neigh == parent)
                continue;
            if(visited[neigh] == 1)
                return true;
            else if(dfs(neigh, v, adj, visited))
                return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int parent = -1;
        vector<int> visited(V, 0);
        for(int i = 0; i<V; i++) {
            if(!visited[i] && dfs(i, parent, adj, visited))
            return true;
        }
        return false;
    }
};
