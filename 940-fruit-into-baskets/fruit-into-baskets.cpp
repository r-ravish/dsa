class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int maxLen = INT_MIN;
        int left=0;
        for(int i=0; i<fruits.size(); i++){
            mpp[fruits[i]]++;
            if(mpp.size() <= 2){
                maxLen = max(maxLen, i-left+1);
            }else{
                while(mpp.size() > 2){
                    mpp[fruits[left]]--;
                    if(mpp[fruits[left]] == 0){
                        mpp.erase(fruits[left]);
                    }
                    left++;
                }
                
            }
        }

        return maxLen;
    }
};