class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int left = 0;
        int maxLen = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeros++;
            }

            if(zeros <= k){
                maxLen = i-left+1;
            }else{
                if(nums[left] == 0) zeros--;
                left+=1;
            }
        }

        return maxLen;
    }
};