class Solution {
public:
// binSrch O(log(n))
// NM...POD
// FS_..B...EXMS

char nextGreatestLetter(vector<char> &letters, char target)
{
    int n = letters.size();
    char ans = letters[0];
    int left = 0, right = (n-1);

    if(ans>target)
        return ans;

    if(target>= letters[n-1])
        return ans;

    while(left<=right){
        int mid = (right+left)/2;

        if(letters[mid]>target){
            ans = letters[mid];
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
   return ans;
}
};