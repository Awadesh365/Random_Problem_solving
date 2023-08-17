class Solution {
public:
string isBalanced(string s)
{
    int n = s.size();
    stack<char> ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            ans.push(s[i]);
        else
        {
            if (ans.empty())
                return "NO";

            if (s[i] == ')')
            {
                char last = ans.top();
                ans.pop();
                if (last != '(')
                    return "NO";
            }
            if (s[i] == '}')
            {
                char last = ans.top();
                ans.pop();
                if (last != '{')
                    return "NO";
            }
            if (s[i] == ']')
            {
                char last = ans.top();
                ans.pop();
                if (last != '[')
                    return "NO";
            }
        }
    }
    if (ans.empty())
        return "YES";

    return "NO";
}
    bool isValid(string s) {
        string ans = isBalanced(s);
        if(ans=="YES")
            return true;

        return false;
    }
};