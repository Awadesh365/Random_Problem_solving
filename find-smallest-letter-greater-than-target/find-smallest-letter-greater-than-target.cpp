class Solution {
public:
// approach 1: - brute force
// O(n)
char nextGreatestLetter(vector<char> &letters, char target)
{
    char ans = letters[0];
   for(auto &it:letters){
       if(it>target){
           ans = it;
           break;
       }
   }
   return ans;
}
};