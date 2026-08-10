class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if((int)ch >= 65 && (int)ch <= 90){
                ch = (int)ch + 32;
            }

            ans+=ch;
        }

        return ans;
    }
};