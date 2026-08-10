class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i=shifts.size()-2; i>=0; i--){
            shifts[i] = (shifts[i] + shifts[i+1])%26;
        }

        string ans = "";
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            ch = ((int)s[i] + shifts[i] - 'a')%26 + 'a';
            ans+=ch;
        }

        return ans;
    }
};