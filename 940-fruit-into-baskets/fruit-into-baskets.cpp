class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int left = 0;
        int right = 0;
        int maxLen = INT_MIN;

        while(right < nums.size()){
            mpp[nums[right]]++;
            if(mpp.size() <= 2){
                maxLen = max(maxLen, right-left+1);
            }else{
                while(mpp.size() > 2){
                    mpp[nums[left]]--;
                    if(mpp[nums[left]] == 0){
                        mpp.erase(nums[left]); 
                    }
                    left++;
                }
                maxLen = max(maxLen, right-left+1);
            }

            right++;
        }

        return maxLen;
    }
};