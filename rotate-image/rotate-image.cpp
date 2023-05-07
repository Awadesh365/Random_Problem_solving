class Solution {
public:
    /*
    Optimal sol:-
     using the Concept of Transpose of matrix
    in which, all the rows becomes columns, and all columns becomes rows in a matrix.

    after that we just have to reverse each row, to get the desired output.
    */
    // SC:- O(1), since i am just doing in-place
    // TC: O(n*m) + (n^2) to iterate over the matrix and 
    //   reverse and other operations.
    
    void rotate(vector<vector<int>>& matrix) {

        // code to perform transpose of matrix
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<i;j++)
                swap(matrix[i][j],matrix[j][i]);
            
        for(int i=0;i<matrix.size();i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};