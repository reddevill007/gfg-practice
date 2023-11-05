//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void BFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<int> &result) {
        queue<int> todo;
        todo.push(u);
        visited[u] = true;
        result.push_back(u);
        
        while(!todo.empty()) {
            int top = todo.front();
            todo.pop();
            
            for(int &v: adj[top]) {
                if(!visited[v]) {
                    todo.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
    
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> mp[]) {
        unordered_map<int, vector<int>> adj;
        
        for(int u = 0; u < V; u++) {
            for(auto v = mp[u].begin(); v != mp[u].end(); v++) {
                adj[u].push_back(*v);
            }
        }
        
        vector<int> result;
        vector<bool> visited(V, false);
        
        BFS(adj, 0, visited, result);
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends