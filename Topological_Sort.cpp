class Solution
{
	public:
	
	void dfs(int v, vector<int> adj[], vector<int> &visited, stack<int> &st) {
	    visited[v] = 1;
	    for(auto &neigh: adj[v]) {
	        if(!visited[neigh])
	            dfs(neigh, adj, visited, st);
	    }
	    st.push(v);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> st;
	    vector<int> visited(V, 0);
	    for(int i = 0; i<V; i++) {
	        if(!visited[i])
	        dfs(i, adj, visited, st);
	    }
	    vector<int> topo;
	    while(!st.empty()) {
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
	}
};
