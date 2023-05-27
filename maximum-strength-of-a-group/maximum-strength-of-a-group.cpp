class Solution
{
public:
    typedef long long ll;
    ll maxStrength(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        vector<int> pos, neg;
        for (auto &it : nums)
        {
            if (it > 0)
                pos.push_back(it);
            else if (it < 0)
                neg.push_back(it);
        }

        ll prod = (ll)1;
        for (auto &it : nums)
            if (it != 0)
                prod *= (ll)it;
        
        set<int> chk;
        for (auto &it : nums)
            chk.insert(it);

        if (chk.size() == 1)
        {
            for (auto &it : chk)
                if (it == 0)
                    return 0;
        }

        if (neg.size() & 1)
        {
            if (neg.size() == 1)
            {
                if (chk.size() == 2)
                {
                    for (auto &it : chk)
                        if (it == 0)
                            return 0;
                }
            }
            
            sort(neg.begin(), neg.end(), greater<int>());
            prod = (prod / neg[0]);

            return prod;
        }

        return prod;
    }
};