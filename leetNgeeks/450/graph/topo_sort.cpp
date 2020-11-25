// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/

void topo_util(int u, vector<int> &vis, vector<int> g[],stack<int> &st) {
    
    vis[u] = 1;
    
    for(int i = 0; i < g[u].size(); i++ ) {
        
        if(vis[g[u][i]] == 1  ) {
            
        }
        else if(vis[g[u][i]] != 2) {
            topo_util(g[u][i], vis, g,st);
        }
    }
    st.push(u);
    vis[u] = 2;
    
}

vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    
    vector<int> ans;
    vector<int> vis(V,0);
    
    stack<int> st;
    
    for(int i = 0; i < V; i++) {
        if(vis[i] == 0)
            topo_util(i,vis,adj,st);
    }
    
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
    
    
}
