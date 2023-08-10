class Solution {
public:
// TmComp:- O(n)
// SpComp:- O(1)
    int fib(int n) {
        if(n<=1)
            return n;

        int prev = 1,prev2 = 0;
        for(int i=2;i<=n;i++){
            int current = prev + prev2;
            prev2= prev;
            prev = current;
        }

        return prev;
    }
};