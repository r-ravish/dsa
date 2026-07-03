class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string check_s = "";

        for(int i=size(s)-1; i>=0; i--){
            check_s+=s[i];
        }

        if(s==check_s){
            return true;
        }
        else{
            return false;
        }

    }
};