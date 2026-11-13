class Solution {
public:

    double solve(double x, long long N) {

        if(N==0){
            return 1;
        }

        double half = myPow(x,N/2);

        if(N%2==0){
            return half*half;
        }else{
            return half*half*x;
        }
    }

    double myPow(double x, int n) {

        long long N = n;
        bool negative = (N < 0);

        if (negative) {
            N = -N;
        }

        double ans = solve(x, N);

        if (negative) {
            return 1.0 / ans;
        }

        return ans;
    }
};