class Solution {
public:
    void genValisStrings(int ind, int n, vector<string>& ans, string& temp){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        if(temp.size() == 0 || temp[ind-1] == '1'){
            temp+="0";
            genValisStrings(ind+1, n, ans, temp);
            temp.pop_back();
        }
        
        temp+="1";
        genValisStrings(ind+1, n, ans, temp);
        temp.pop_back();
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string s;

        genValisStrings(0, n, ans, s);

        return ans;

    }
};