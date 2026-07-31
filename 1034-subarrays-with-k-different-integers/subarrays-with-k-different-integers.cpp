class Solution {
public:
    int temp(vector<int>& nums, int k){
        if(k<0) return 0;
        unordered_map<int,int> mpp;
        int left=0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
            while(mpp.size() > k){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            if(mpp.size() <= k){
                ans+=(i-left+1);
            }
            
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a = temp(nums,k);
        int b = temp(nums,k-1);
        return a-b;
    }
};