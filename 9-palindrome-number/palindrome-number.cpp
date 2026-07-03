class Solution {
public:
    bool isPalindrome(int x) {
        int a = x;
        long long c = 0;
        while(a > 0){
            int temp = a%10;
            c=c*10 + temp;
            a=a/10;
        }

        return c == x;
    }
};