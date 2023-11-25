//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool checkBipartiteDFS(vector<int>adj[], int curr, vector<int> &color, int currColor) {
        color[curr] = currColor;
        
        for(int &v : adj[curr]) {
            
            if(color[v] == color[curr])
                return false;
            
            if(color[v] == -1) {
                
                int colorOfV = 1 - currColor;
                
                if(checkBipartiteDFS(adj, v, color, colorOfV) == false)
                    return false;
            }
            
        }
        
        return true;
        
    }
    
    bool checkBipartiteBFS(vector<int>adj[], int curr, vector<int> &color, int currColor) {
        queue<int> todo;
        todo.push(curr);
        color[curr] = currColor;
        
        while(!todo.empty()) {
            int u = todo.front();
            todo.pop();
            
            for(int v: adj[u]) {
                if(color[u] == color[v]) {
                    return false;
                }
                else if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    todo.push(v);
                }
            }
            
        }
        return true;
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V, -1);
	    
	   for(int i = 0; i < V; i++) {
	       if(color[i] == -1) {
	           if(checkBipartiteBFS(adj, i, color, 1) == false) return false;
	       }
	   }
	   
	   return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends