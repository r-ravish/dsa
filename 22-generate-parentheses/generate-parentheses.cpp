class Solution {
public:
    void totalParenthesis(int open, int close, int n, string& s, vector<string>& ans, int num){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }

        if(open < n){
            s+="(";
            open+=1;
            totalParenthesis(open, close, n, s, ans, num);
            open-=1;
            s.pop_back();
        }
        if(close < open){
            s+=")";
            close+=1;
            totalParenthesis(open, close, n, s, ans, num);
            close-=1;
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;

        totalParenthesis(0, 0, n, s, ans, 0);

        return ans;
    }
};