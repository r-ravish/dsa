class Solution {
public:
    double calculatePower(double x, long long n){
        if(n==0) return 1;
        double ans = calculatePower(x,n/2);
        if(n%2 == 0){
            return ans*ans;
        }
        
        return x*ans*ans;

    }

    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==1) return 1;

        long long N=n;
        if(n<0){
            double out = calculatePower(x, -N);
            return 1/out;
        }

        return calculatePower(x, N);
    }
};