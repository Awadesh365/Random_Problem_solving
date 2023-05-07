class Solution {
public:
// POD
vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
{
    int n = obstacles.size();

    // dp[i]  records the lowest increasing sequence of length (i+1)
    vector<int> dp;

    vector<int> answer(n, 1);

    for (int i = 0; i < n; i++)
    {
        // find the rightmost insertion position idx
        int idx = upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();
        if (idx == dp.size())
            dp.push_back(obstacles[i]);
        else
            dp[idx] =obstacles[i];

        answer[i] = idx + 1;
    }

    return answer;
}
};