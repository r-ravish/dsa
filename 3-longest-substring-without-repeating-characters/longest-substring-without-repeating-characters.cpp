class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0;
        int out = 0;
        int n=s.size();
        for(int i=0; i<n; i++){
            while(st.contains(s[i])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
            out=max(i-left+1, out);
        }

        return out;
    }
};