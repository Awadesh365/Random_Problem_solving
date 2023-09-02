class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        stack<int>st;
        for(int i = nums2.size()-1;i>= 0; i--){
            while(!st.empty() and nums2[i] > st.top()){
                st.pop();
            }
            if(!st.empty()){
                mp[nums2[i]] = st.top();
            }
            else{
                mp[nums2[i]]=-1;
            }
            st.push(nums2[i]);
        }
    for(int i=0;i<nums1.size();i++){
        nums1[i] = mp[nums1[i]];
    }
    return nums1;
    }
};