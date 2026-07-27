class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        if(s == ""){
            return 0;
        }


        int left = 0;
        int maxLen = INT_MIN;
        for(int i=0; i<s.size(); i++){
            int len = 0;
            if(mpp.contains(s[i]) && mpp[s[i]] >= left){
                left=mpp[s[i]] + 1;
                mpp[s[i]] = i;
            }else{
                mpp[s[i]] = i;
            }
            len = i - left + 1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};