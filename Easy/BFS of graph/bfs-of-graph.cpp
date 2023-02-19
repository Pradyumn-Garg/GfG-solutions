//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector <int> ans;
        queue <int> curr;
        curr.push(0);
        ans.push_back(0);
        while(!curr.empty()){
            vector <int> currnode = adj[curr.front()];
            curr.pop();
            for(int i=0;i<currnode.size();i++){
                auto temp = find (ans.begin(), ans.end(), currnode[i]);
                if(temp!= ans.end()){
                    continue;
                }
                ans.push_back(currnode[i]);
                curr.push(currnode[i]);
            }
        }
        return ans;
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