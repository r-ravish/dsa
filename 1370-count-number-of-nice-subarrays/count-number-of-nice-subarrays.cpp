class Solution {
public:
    int niceSubarrays(vector<int>& nums, int k){
        int ans = 0;
        int left = 0;
        int oddCount = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 != 0){
                oddCount++;
            }

            while(oddCount > k){
                if(nums[left]%2 != 0){
                    oddCount--;
                }
                left++;
            }
            if(oddCount <= k){
                ans+=(i-left+1);
            }
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int a = niceSubarrays(nums, k);
        int b = niceSubarrays(nums, k-1);

        return a-b;
    }
};