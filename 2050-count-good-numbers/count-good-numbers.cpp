class Solution {
public:
    long long powCount(int x, long long n){
        const long long MOD = 1000000007;
        if(n==0) return 1;
        long long ans = powCount(x, n/2);
        if(n%2 == 0){
            return (ans*ans)%MOD;
        }
        return (ans*ans*x)%MOD;
    }

    int countGoodNumbers(long long n) {
        const long long MOD = 1000000007;
        long long N = n/2;
        if(n%2 != 0){
            return (powCount(4, N) * powCount(5, N+1))%MOD;
        }return (powCount(4, N) * powCount(5, N))%MOD;
    }
};