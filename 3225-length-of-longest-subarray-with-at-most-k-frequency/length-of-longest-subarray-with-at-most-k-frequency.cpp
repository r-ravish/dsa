class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int left =0;
        int maxLen = 0;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;

            if(mpp[nums[i]]<=k){
                maxLen=max(maxLen, i-left+1);
            }else{
                while(mpp[nums[i]] > k){
                    mpp[nums[left]]--;
                    left++;

                    if(mpp[nums[left]] == 0){
                        mpp.erase(mpp[nums[left]]);
                    }
                }
            }

        }

        return maxLen;
    }
};