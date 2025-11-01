class Solution {
  public:
 
    bool detectCycle(int src,vector<vector<int>>& adj,vector<int> &vis){ //bfs
      queue<pair<int,int>> q; //{node,parent}
      vis[src] = 1;
      q.push({src,-1});

      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          for(auto adjNode : adj[node]){
              if(!vis[adjNode]){
                  vis[adjNode] = 1;
                  q.push({adjNode,node});
              }
              else if(parent != adjNode){ //if node is visited and not parent,
                // it means this node is already visited by another node's path
                  return true;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<int>vis(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectCycle(i,adj,vis) ) return true;
            }
        }
        return false;
    }
};