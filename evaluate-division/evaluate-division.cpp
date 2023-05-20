// #include <bits/stdc++.h>

// using namespace std;

class Solution
{
public:
    // pod 
    // learned about how to write and come up with sol in graphs probs
    unordered_map<string, vector<pair<string, double>>> graph;
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            string start = equations[i][0];
            string end = equations[i][1];
            double val = values[i];

            graph[start].push_back({end, val});
            graph[end].push_back({start, (double)1 / val});
        }

        vector<double> result;
        for (auto query : queries)
        {
            unordered_set<string> visited;
            result.push_back(dfs(query[0], query[1], visited));
        }
        return result;
    }

    double dfs(string src, string dst, unordered_set<string> &visited)
    {
        if (graph.find(src) == graph.end())
            return -1;
        if (src == dst)
            return 1;

        for (auto node : graph[src])
        {
            if (visited.count(node.first))
                continue;
            visited.insert(node.first);
            double res = dfs(node.first, dst, visited);
            if (res != -1)
                return res * node.second;
        }
        return -1;
    }
};

// int main()
// {
//     Solution sol;
//     vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}, {"c", "a"}};
//     vector<double> values = {2.0, 3.0, 4.0};
//     vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"c", "b"}};

//     vector<double> result = sol.calcEquation(equations, values, queries);
//     for (double val : result)
//     {
//         cout << val << endl;
//     }

//     return 0;
// }
