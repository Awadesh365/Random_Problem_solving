class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto &it:nums){
            freq[it]++;
        }
        for(auto &it:nums){
            if(freq[it]>=2)
                return true;
        }

    return false;
    }
};