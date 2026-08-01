class Solution {
public:
    string reversePrefix(string word, char ch) {
        int left = 0;
        int i=0;
        string ans = "";
        while(i<word.size()){
            if(word[i] == ch){
                break;
            }
            i++;
        }
        if(i==word.size()){
            return word;
        }

        int right = i;
        while(right >= 0){
            ans+=word[right];
            right--;
        }
        i++;
        while(i<word.size()){
            ans+=word[i];
            i++;
        }

        return ans;
    }
};