class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> mpp;
        int left = 0;
        int cnt=0;
        int minLen = INT_MAX;
        int startPoint = -1;
        for(int i=0; i<t.size(); i++){
            mpp[t[i]]++;
        }

        for(int i=0; i<s.size(); i++){
            if(mpp[s[i]] > 0){
                cnt++;
            }
            mpp[s[i]]--;

            while(cnt == t.size()){
                if(i-left+1 < minLen){
                    minLen = i-left+1;
                    startPoint = left;
                }
                mpp[s[left]]++;
                if(mpp[s[left]] > 0){
                    cnt--;
                }
                left++;
            }
        }

        return startPoint == -1 ? "" : s.substr(startPoint, minLen);
    }
};