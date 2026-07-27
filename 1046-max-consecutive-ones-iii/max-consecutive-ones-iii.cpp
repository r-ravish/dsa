class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int left = 0;
        int maxLen = INT_MIN;
        int len = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeros++;
            }

            while(zeros > k){
                if(nums[left] == 0) zeros--;
                left++;
            }

            if(zeros <= k){
                len = i-left+1;
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};