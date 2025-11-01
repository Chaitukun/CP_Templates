bool dfs(int node,int parent,vector<int>&vis, vector<int> adj[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
           if (dfs(it,node,vis,adj))
           {
               return true;
           }
        }
        else if(it != parent){ //if visited and not parent,there is a cycle
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m){
    // Write your code here.
    vector<int>adj [n + 1]; // 1-based indexing
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,adj)) { //{node,parent }
                    return "Yes";
            }
            
        }
    }
    return "No";
    
}
