class Solution{
public:
    void dfs(int node, stack<int> &st,vector<int> &vis,vector<int> &adj[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,st,vis,adj);
            }
        }
        /* Add the current node to stack once all the nodes connected to it 
        have been processed */
        st.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> ans;
        stack<int> st;
        vector<int> vis(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,st,vis,adj);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


