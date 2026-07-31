class Solution {
public:
    int lessthanEqual(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int sum = 0;
        int left = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            while(sum > goal){
                sum-=nums[left];
                left++;
            }
            if(sum <= goal){
                ans+=(i-left+1);
            }
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a = lessthanEqual(nums, goal);
        int b = lessthanEqual(nums, goal-1);

        return a-b;
    }
};