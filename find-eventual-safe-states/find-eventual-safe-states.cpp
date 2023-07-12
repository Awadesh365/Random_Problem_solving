class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visit, vector<bool> &inStack)
    {
        // is stack contains node already, then we have a cycle
        if (inStack[node])
            return true;

        if (visit[node])
            return false;

        // mark current node as visited and part of current recursion stack
        visit[node] = true;
        inStack[node] = true;
        for (auto &neighbor : adj[node])
            if (dfs(neighbor, adj, visit, inStack))
                return true;

        // removing the node from stack
        inStack[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++)
            for (auto &node : graph[i])
                adj[i].push_back(node);

        vector<bool> visit(n), inStack(n);

        for (int i = 0; i < n; i++)
            dfs(i, adj, visit, inStack);

        vector<int> safeNodes;
        for (int i = 0; i < n; i++)
            if (!inStack[i])
                safeNodes.push_back(i);

        return safeNodes;
    }
};