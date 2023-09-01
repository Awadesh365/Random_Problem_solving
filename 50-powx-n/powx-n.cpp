
class Solution {
public:
    /*
        This Problem Teaches us the Use case of 
        Mathematics in Programing,
        In this problem the Binary Exponentiation is used, which is Better than "pow(x,n)" function in c++
    */
    double binaryExponentiation(double x, long long n){
        if(n==0)
            return 1;

        if(n<0)
            return (1.0)/binaryExponentiation(x,(-1*n));

        if(n%2 == 1)
            return x*binaryExponentiation(x*x,(n-1)/2);

     return binaryExponentiation(x*x,n/2);

    }
    double myPow(double x, int n) {
        long long bigN = n;
        return binaryExponentiation(x,bigN);
    }
};