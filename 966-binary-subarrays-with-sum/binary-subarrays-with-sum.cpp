class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mpp;
        int maxLen = 0;
        int sum=0;
        mpp[0]=1;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(mpp.contains(sum-goal)){
                maxLen+=mpp[sum-goal];
            }
            mpp[sum]++;
        }

        return maxLen;
    }
};