class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

       set<int>dummy;
       for(auto &it:nums){
           dummy.insert(it);
       }
        nums.clear();
        for(auto &it:dummy)
            nums.push_back(it);

        return nums.size();
    }
};