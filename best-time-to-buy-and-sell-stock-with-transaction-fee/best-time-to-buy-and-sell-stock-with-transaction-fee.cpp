class Solution {
public:
   int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    int free = 0, hold = -prices[0];

    for (int i = 0; i < n; i++)
    {
        int temp = hold;
        hold = max(hold, free - prices[i]);
        free = max(free, temp + prices[i] - fee);
    }
    return free;
}
};