class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> ans;
        vector<int> indegree(V,0);
        //calculate indegree of each node
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        //push all nodes with indegree 0 into the queue
        for(int i=0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }

        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            //reduce indegree of adjacent nodes
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return ans;

    }
};
