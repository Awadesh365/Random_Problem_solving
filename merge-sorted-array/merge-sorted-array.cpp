class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        for(int i=(nums1.size()-1);i>=0;--i){
            if(nums1[i]==0)
                nums1.pop_back();
            else
                break;
        }
        
        for(auto &it:nums2)
            nums1.push_back(it);

        while(nums1.size()<(m+n))
            nums1.push_back(0);

        sort(nums1.begin(),nums1.end());
    }
};