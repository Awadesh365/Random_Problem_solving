class Solution
{
public:
    // br...mrg -> fk...sb -> NM -> POD
    typedef long long ll;
    ll costFinder(vector<int>& nums, vector<int>& cost, int element)
    {
        ll ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ll a = abs(nums[i] - element);
            ans += (a * cost[i]);
        }
        return ans;
    }

    ll minCost(vector<int>& nums, vector<int>& cost)
    {
        ll minElement = LLONG_MAX, maxElement = INT_MIN;
        for (auto it : nums)
        {
            minElement = min(static_cast<ll>(minElement), static_cast<ll>(it));
            maxElement = max(static_cast<ll>(maxElement), static_cast<ll>(it));
        }
        ll ans = LLONG_MAX;
        while (minElement <= maxElement)
        {
            int mid = minElement + (maxElement - minElement) / 2;
            ll tempVariable = costFinder(nums, cost, mid);
            ans = min(ans, tempVariable);

            ll right = costFinder(nums, cost, mid + 1);
            ll left = costFinder(nums, cost, mid - 1);

            if (tempVariable < left && tempVariable < right)
            {
                return ans;
            }
            else if (tempVariable < left && tempVariable > right)
            {
                minElement = mid+1;
            }
            else
            {
                maxElement = mid - 1;
            }
        }
        return ans;
    }
};
