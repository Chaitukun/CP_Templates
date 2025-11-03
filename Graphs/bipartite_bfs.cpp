class Solution {
public:
// colors graph with alternating 0,1's
    bool bfs(int source,int col, vector<int>&color,vector<vector<int>>& graph){
        queue<int> q;
        color[source] = col;
        q.push(source); //push stsrt node and mark as visited or colored
       
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &it : graph[node]){
                if(color[it] == -1){ //not colored or unvisited
                    color[it] = ! color[node]; //give opp color
                    q.push(it);
                }
                else if(color[it] == color[node]){ // adjNode has same color as node
                    return false;
                }
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v,-1);


        // checking for components 
        for(int i=0;i<v;i++){
            if(color[i] == -1){
                if(bfs(i,0,color,graph) == false) return false;
            }
        }
        return true;
    }
};