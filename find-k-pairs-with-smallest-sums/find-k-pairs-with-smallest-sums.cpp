// #include <bits/stdc++.h>
// using namespace std;

// nm-> brs mrg-> fk sbs-> pod
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> result;
        set<pair<int, int>> visited;

        auto comp = [&](const pair<int, pair<int, int>> &p1, const pair<int, pair<int, int>> &p2)
        {
            return nums1[p1.second.first] + nums2[p1.second.second] > nums1[p2.second.first] + nums2[p2.second.second];
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> minHeap(comp);

        minHeap.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});

        while (k-- && !minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();
            int i = top.second.first;
            int j = top.second.second;

            result.push_back({nums1[i], nums2[j]});

            if (i + 1 < m && visited.find({i + 1, j}) == visited.end())
            {
                minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if (j + 1 < n && visited.find({i, j + 1}) == visited.end())
            {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return result;
    }
};


// int main()
// {
//     return 0;
// }