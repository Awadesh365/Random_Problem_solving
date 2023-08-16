class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<string> listOfElements;
        vector<vector<string>> allPossiblePalindromePartining;
        solve(0, s, listOfElements, allPossiblePalindromePartining);
        return allPossiblePalindromePartining;
    }

public:
    bool isPalindrome(string &str, int s, int e)
    {
        int n = str.size();
        while (s <= e)
        {
            if (str[s++] != str[e--])
                return false;
        }
        return true;
    }

public:
    void solve(int index, string &s, vector<string> &SampleSubString, vector<vector<string>> &allPossiblePalindromePartining)
    {
        if (index == s.size())
        {
            allPossiblePalindromePartining.push_back(SampleSubString);
            return;
        }
        string str = "";
        for (int i = index; i < s.size(); i++)
        {
            str += s[i];
            if (isPalindrome(s, index, i) == true)
            {
                SampleSubString.push_back(str);
                solve(i + 1, s, SampleSubString, allPossiblePalindromePartining);
                SampleSubString.pop_back(); // Backtrack
            }
        }
    }
};