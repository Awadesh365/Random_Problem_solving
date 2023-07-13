class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&instack)
{
    // cycle -> if node is already present
    if(instack[node])
        return true;

    if(visited[node])
        return false;

        // current node as visited since we are traversing
    visited[node] = true;
    instack[node] = true;

    for(auto &neighbor:adj[node]){
        if(dfs(neighbor,adj,visited,instack))
            return true;
    }
    // removal of node
    instack[node] = false;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    for(auto &prerequisite:prerequisites){
        adj[prerequisite[1]].push_back(prerequisite[0]);
    }
    vector<bool> visit(numCourses), instack(numCourses);
    for (int i = 0; i < numCourses;i++){
        if(dfs(i,adj,visit,instack))
            return false;
    }
    return true;
}
};