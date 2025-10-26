class Solution {
private: 
    double Pow(double x, long long n){
        if(n == 0) return 1;
        double half = Pow(x,n/2);
        if(n%2 == 0) return half * half;
        else return half * half * x;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0){
            N = -N;
            x = 1/x;
        }
        return Pow(x,N);
    }
};


// best way
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0) N = -N;

        double ans= 1.0;
        while(N>0){
            if(N%2 == 1){
                ans *= x;
                N -= 1;
            }else{
                N /=2;
                x *=x;
            }
        }

        return n < 0 ? 1/ans:ans;
    }
};