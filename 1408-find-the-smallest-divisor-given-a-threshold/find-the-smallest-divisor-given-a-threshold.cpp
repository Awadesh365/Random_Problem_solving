class Solution{
public:
    int smallestDivisor(vector<int> &nums, int threshold){
        
        int n = nums.size();
        int ans = *max_element(nums.begin(),nums.end());

        int left = 1, right = ans;
        while (left <= right){
            int mid = left + (right - left) / 2;

            int sum = 0;
            for (auto &it : nums){
                // here i was stucked, the double needs to add only.
                sum += ceil((double)it / (double)mid);
            }
            if(sum<=threshold){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans ;
    }
};