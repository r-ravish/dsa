class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        int start = -1;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                cnt++;
            }

            while(cnt>=k){
                if(s[left] == '1'){
                    cnt--;
                }
                if(minLen > i-left+1){
                    start = left;
                    minLen = i-left+1;
                }else if(minLen == i-left+1){
                    string curr = s.substr(left, minLen);
                    string best = s.substr(start, minLen);

                    if (curr < best) {
                        start = left;
                    }
                }
                left++;
            }
        }

        if(start == -1){
            return "";
        }

        return s.substr(start, minLen);
    }
};