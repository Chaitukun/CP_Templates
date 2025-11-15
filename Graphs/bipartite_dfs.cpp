class Solution {
public:
// colors graph with alternating 0,1's
    bool dfs(int node,int col, vector<int>&color,vector<vector<int>>& graph){
        color[node] = col;
        for(auto it : graph[node]){
            if(color[it] == -1){ // if adjNode is not colored yet
                if(dfs(it,!col,color,graph) == false) return false;
            }
            else if(color[it] == col){ // colored but, adjNode's having same color
                return false;
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);


        // checking for components 
        for(int i=0;i<v;i++){
            if(color[i] == -1){
                if(dfs(i,0,color,graph) == false) return false;
            }
        }
        return true;
    }
};