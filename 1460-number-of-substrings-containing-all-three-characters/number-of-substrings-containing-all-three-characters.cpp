class Solution {
public:
    // int mini(int a, int b, int c){
    //     int temp = min(a,b);
    //     int newTemp = min(temp,c);
    //     return newTemp;
    // }

    int numberOfSubstrings(string s) {
        int ans = 0;
        unordered_map<char, int> mpp = {{'a', -1}, {'b', -1}, {'c', -1}};
        for(int i=0; i<s.size(); i++){
            mpp[s[i]] = i;
            
            if(mpp['a'] != -1 && mpp['b'] != -1 && mpp['c'] != -1){
                // int temp = mini(mpp['a'], mpp['b'], mpp['c']);
                int temp = min({mpp['a'], mpp['b'], mpp['c']});
                ans+=(temp+1);
            }
        }
        return ans;
    }
};