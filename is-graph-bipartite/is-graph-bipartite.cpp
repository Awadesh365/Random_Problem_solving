class Solution {
public:
    // POD
    // learned about bipertite graphs
    // usecases of bfs and dfs  
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,0);

        for(int node=0;node<n;node++){
            if(color[node]!=0) continue;

            queue<int>q;
            q.push(node);

            color[node]=1;
            
            while(!q.empty()){
                int cur = q.front();
                q.pop();

                for(int ne : graph[cur]){
                    if(color[ne] == 0){
                        color[ne]=-color[cur];
                        q.push(ne);
                    }
                    else if(color[ne] != -color[cur]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};