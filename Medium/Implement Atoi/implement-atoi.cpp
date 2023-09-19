//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int ans=0;
        int sign = 1;

        int i=0;
        if(s[i] == '-'){
          sign = -1;
          i++;
        }

      for(i;i<s.size();i++){
        if((s[i] - '0') <= 9 && (s[i] - '0')>=0)
          ans = (ans*10) + s[i]-'0';
         else
            return -1;
      }
    return sign*ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends