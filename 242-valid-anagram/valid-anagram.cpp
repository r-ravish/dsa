class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mppS;
        for(int i=0; i<s.size(); i++){
            mppS[s[i]]++;
        }
        bool ans = false;
        unordered_map<char, int> mppT;
        for(int i=0; i<t.size(); i++){
            mppT[t[i]]++;
        }

        if(mppS == mppT){
            return true;
        }return false;

        return ans;
    }
};