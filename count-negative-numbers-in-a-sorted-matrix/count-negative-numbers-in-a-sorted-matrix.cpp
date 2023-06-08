class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;

        // bin srch O(n*log(n))
        for(auto &it:grid){
            cnt+= upper_bound(it.rbegin(),it.rend(),-1)-it.rbegin();
        }
        return cnt;
    }
};