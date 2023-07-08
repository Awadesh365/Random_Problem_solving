class Solution {
public:
    typedef long long ll;
    long long putMarbles(vector<int> &weights, int k)
    {
        ll n = weights.size();
        vector<ll> selectedCandidates;
        for (ll i = 1; i < n; i++)
            selectedCandidates.push_back(weights[i - 1] + weights[i]);

        sort(selectedCandidates.begin(), selectedCandidates.end(), greater<ll>());

        // there are k paritions
        // adding wegiths in maxSum from starting,and adding weights in minSum from ending, since the array is sorted in decreasing order

        ll m = selectedCandidates.size();

        ll maxSum = 0, minSum = 0;
        for (ll i = 0; i < k - 1; i++)
            maxSum += selectedCandidates[i], minSum += selectedCandidates[(m - 1) - i];

        return ((maxSum - minSum) > 0 ? (maxSum - minSum) : 0);
    }
};