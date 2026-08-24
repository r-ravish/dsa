class Solution {
public:
    bool isPalindrome(string chck){
        int n = chck.size();
        for(int i=0; i<n/2; i++){
            if(chck[i] != chck[n-i-1]){
                return false;
            }
        }
        return true;
    }

    void genPartition(string s, int ind, vector<vector<string>>& ans, vector<string>& temp, int n){
        if(ind >= n){
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<n; i++){
            string check = s.substr(ind, i-ind+1);
            if(isPalindrome(check) && check.size() != 0){
                temp.push_back(check);
                genPartition(s, i+1, ans, temp, n);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp; 
        int n = s.size();

        genPartition(s, 0, ans, temp, n);

        return ans;
    }
};