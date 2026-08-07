class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        unordered_map<char, int> mpp;
        int maxLen = 0;
        int maxfreq = INT_MIN;
        int temp = 0;
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
            if(mpp[s[i]] > maxfreq){
                maxfreq = mpp[s[i]];
            }

            if(i-left+1 - maxfreq <= k){
                maxLen = i-left+1;
            }
            while(i-left+1 - maxfreq > k){
                mpp[s[left]]--;
                left++;
            }
        }

        return maxLen;
    }
};