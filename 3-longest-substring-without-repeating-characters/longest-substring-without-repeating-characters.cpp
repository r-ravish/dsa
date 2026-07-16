class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        vector<int> arr(256, -1);
        int ans = -1;
        int left = 0;
        for(int i=0; i<s.size(); i++){
            if(arr[s[i]] >= left){
                left=arr[s[i]] + 1;
            }
            ans = max(i-left+1, ans);
            arr[s[i]]=i;
        }

        return ans;


    }
};