class Solution {
public:
    bool isPossible(vector<int>arr,int idx,int days){
    int ans = 0, cnt = 1;
    for(auto &it:arr){
        if(ans+it<=idx)
            ans += it;
        else{
            cnt++;
            ans = it;
        }
    }
    if(cnt<=days)
        return true;

    return false;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int mn = *max_element(weights.begin(), weights.end());

    int mx = 0;
    for(auto &it:weights){
        mx += it;
    }

    int ans = mx;

    int left = mn, right = mx;
    while(left<=right){
        int mid = left + (right - left) / 2;

        if(isPossible(weights,mid,days)){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}
};