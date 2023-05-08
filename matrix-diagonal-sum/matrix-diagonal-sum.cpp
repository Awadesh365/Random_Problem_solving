class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        for(int i=0;i<mat.size();i++){
            sum+=mat[i][i];  // primary diagnal

            sum+=mat[i][mat.size()-1-i];// secondary diagnal
        }

        if(mat.size()&1)
          return sum-mat[mat.size()/2][mat.size()/2];
        return sum;

    }
};