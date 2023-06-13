class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {   
       // Last NM...POD, exms excs
       int cnt = 0;
       int n = grid.size();
 vector<vector<int>>ans(n,vector<int>(n));

       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid.size();j++){
               ans[i][j] = grid[j][i];
           }
       }
    for(auto &it:grid){
        for(auto &kt:ans){
            if(it==kt)
                cnt++;
        }
     }
    return cnt;
    }

};