class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> ans(s.size() + 1, 0);
        for(int i=0; i<shifts.size(); i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if(direction == 1){
                ans[start]+=1;
                if(end+1 < s.size()) ans[end+1]-=1;
                
            }else{
                ans[start]-=1;
                if(end+1 < s.size()) ans[end+1]+=1;
            }
            
        }

        for(int i=1; i<s.size(); i++){
            ans[i]+=ans[i-1];
        }

        string out = "";
        for(int i=0; i<ans.size()-1; i++){
            int x = (s[i]-'a'+ans[i])%26;
            if(x<0){
                x+=26;
            }
            out+=char('a' + x);
        }
        return out;
    }
};