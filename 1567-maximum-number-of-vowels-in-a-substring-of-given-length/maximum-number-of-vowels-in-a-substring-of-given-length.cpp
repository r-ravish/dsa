class Solution {
public:
    bool isVowel(char c){
        return c =='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    int maxVowels(string s, int k) {
        int left=0;
        int cnt=0;
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])){
                cnt++;
            }
            if(i-left+1 > k){
                if(isVowel(s[left])){
                    cnt--;
                }
                left++;
            }
            
            ans=max(ans,cnt);
        }

        return ans;
    }
};