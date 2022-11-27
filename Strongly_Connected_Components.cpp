class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> rev[V];
        stack<int> st;
        vector<int> visited(V, 0);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i])
            dfs(i, adj, visited, st);
        }
        visited = vector<int> (V, 0);
        reverse(V, adj, rev);
        stack<int> dummy;
        int ssc = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(visited[node])
            continue;
            ++ssc;
            dfs(node, rev, visited, dummy);
        }
        return ssc;
    }
    
    void dfs(int v, vector<int> adj[],  vector<int> &visited, stack<int> &st) {
        visited[v] = 1;
        for(auto &neigh: adj[v]) {
            if(!visited[neigh])
            dfs(neigh, adj, visited, st);
        }
        st.push(v);
    }
    
    void reverse(int V, vector<int> adj[], vector<int> rev[]) {
        for(int i = 0; i<V; i++) {
            for(auto &neigh: adj[i]) {
                rev[neigh].push_back(i);
            }
        }
    }
};
