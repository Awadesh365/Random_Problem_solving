// #include <bits/stdc++.h>
// using namespace std;

class Solution
{
public:
    // NM... POD
    // Brs... Mrg-> fk-> sbs
    int countRoutes(vector<int> locations, int start, int finish, int fuel)
    {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1));
        for (int i = 0; i <= fuel; i++)
        {
            dp[finish][i] = 1;
        }

        int ans = 0;
        for (int j = 0; j <= fuel; j++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (k == i)
                    {
                        continue;
                    }
                   else if (abs(locations[i] - locations[k]) <= j)
                    {
                        dp[i][j] = (dp[i][j] + dp[k][j - abs(locations[i] - locations[k])]) %
                                   1000000007;
                    }
                }
            }
        }

        return dp[start][fuel];
    }
};

// int main()
// {

//     return 0;
// }