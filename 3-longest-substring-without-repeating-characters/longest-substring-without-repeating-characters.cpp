class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0;
        if(s.size()==0){
            return 0;
        }
        int out = INT_MIN;

        for(int i=0; i<s.size(); i++){
            while(st.contains(s[i])){
                st.erase(s[left]);
                left++;
            }
            if(!st.contains(s[i])){
                st.insert(s[i]);
                out=max(i-left+1, out);
            }
        }

        return out;
    }
};