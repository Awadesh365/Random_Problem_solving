// #include<bits/stdc++.h>
// using namespace std;

class Solution
{
public:
    // brs mrg-> NM-> Fk sbs -> POD
    // 1. Bellman Ford Algorith
    // 2. Dijkstra's Algorithm
    // understanding how to solVe graph problems
   
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double weight = -log(succProb[i]);
            graph[u].push_back({v, weight});
            graph[v].push_back({u, weight});
        }

        vector<double> distance(n, numeric_limits<double>::max());
        distance[start] = 0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> minHeap;
        minHeap.push({0, start});
        while (!minHeap.empty())
        {
            auto [dist, node] = minHeap.top();
            minHeap.pop();
            if (dist > distance[node])
            {
                continue;
            }
            for (auto [neighbor, weight] : graph[node])
            {
                if (distance[neighbor] > distance[node] + weight)
                {
                    distance[neighbor] = distance[node] + weight;
                    minHeap.push({distance[neighbor], neighbor});
                }
            }
        }

        return distance[end] == numeric_limits<double>::max() ? 0 : exp(-distance[end]);
    }
};

// int main(){

//     Solution s;
//     vector<vector<int>> edges = {{0,1},{1,2},{0,2}};    
//     vector<double> succProb = {0.5,0.5,0.2};
//     int start = 0;
//     int end = 2;
//     int n = 3;
//     cout<<s.maxProbability(n,edges,succProb,start,end)<<endl;

//     return 0;
// 