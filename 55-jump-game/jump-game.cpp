class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLen = 0;
        for(int i=0; i<nums.size(); i++){
            if(i>maxLen){
                return false;
            }
            maxLen = max(maxLen, i+nums[i]);
        }

        return true;
    }
};