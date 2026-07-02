class Solution {
public:
    int reverse(int x) {
        long long temp = x;
        if(temp < 0){
            temp = -temp;
        }
        long long ans = 0;
        while(temp>0){
            int a = temp%10;
            ans = ans*10+a;
            temp=temp/10;
        }
        if(ans > INT_MAX) return 0;
        if(x<0){
            return -ans;
        }return ans;
    }
};