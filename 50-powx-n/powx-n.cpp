class Solution {
public:
    double powCount(double x, long long n){
        if(n==0){
            return 1;
        }
        double ans = powCount(x,n/2);
        if(n%2 == 0){
            return ans*ans;
        }else{
            return ans*ans*x;
        }
    }

    double myPow(double x, int n) {
        long long N = n;
        if(n<0){
            double a = powCount(x,-N);
            return 1/a;
        }

        return powCount(x,N);
    }
};