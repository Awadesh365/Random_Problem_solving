class Solution {
public:
// bs -> O(nlog(n))
    bool canWeExpect(vector<int>arr,int amount,int balls){

    int n = arr.size();
    int cnt = 1;
    int ballPointer = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (amount <= (arr[i]-ballPointer))
        {
            cnt++;
            ballPointer = arr[i];
        }
        if (cnt >= balls)
            return true;
    }
    return false;
}
    int maxDistance(vector<int>& position, int c) {
         sort(position.begin(), position.end());

    int n = position.size();
    int ans = 1;
    int mx = position[(n - 1)];
    int mn = position[0];

    int left = 1;
    int right = (mx - mn);
    while(left<=right){
        int mid = left + (right - left) / 2;

        if(canWeExpect(position,mid,c)){
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    // for (int i = 1; i <=(mx - mn); i++)
    // {
    //     if(canWeExpect(position,i,c)){
    //         ans = i;
    //     }
    //     else
    //         break;
    // }
    return ans;
    }
};