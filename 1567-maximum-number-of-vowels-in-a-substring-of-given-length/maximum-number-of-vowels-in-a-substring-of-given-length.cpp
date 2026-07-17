class Solution {
public:
    int maxVowels(string s, int k) {
        int left=0;
        int cnt=0;
        int ans=0;
        for(int i=0; i<s.size(); i++){
            
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                cnt++;
            }
            if(i-left+1 > k){
                if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u'){
                    cnt--;
                }
                left++;
            }
            if(i-left+1 == k){
                ans=max(ans,cnt);
            }
        }

        return ans;
    }
};