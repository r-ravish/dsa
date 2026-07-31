class Solution {
public:
    int lessthanK(vector<int>& nums, int k){
        if(k<0) return 0;
        int left = 0;
        int odd = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 != 0){
                odd++;
            }
            while(odd > k){
                if(nums[left]%2 != 0) odd --;
                left++;
            }
            if(odd <= k){
                ans+=(i-left+1);
            }
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int a = lessthanK(nums, k);
        int b = lessthanK(nums, k-1);

        return a-b;
    }
};