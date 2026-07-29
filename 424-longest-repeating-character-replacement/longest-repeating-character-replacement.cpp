class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> mpp;
        int maxfreq = INT_MIN;
        int left = 0;
        int maxLen = 0;
        
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
            if(mpp[s[i]] > maxfreq){
                maxfreq = mpp[s[i]];
            }

            if(i-left+1 - maxfreq <= k){
                maxLen = max(maxLen, i-left+1);
            }else{
                // while(i-left+1 - maxfreq > k){
                //     mpp[s[left]]--;
                //     if(mpp[s[left]] == 0){
                //         mpp.erase(s[left]); 
                //     }
                //     left++;
                // }
                mpp[s[left]]--;
                left++;
            }
        }
        return maxLen;
    }
};