class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0;
        double ans=INT_MIN;
        double sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(i-left+1 > k){
                sum-=nums[left];
                left++;
            }
            if(i-left+1 == k){
                double avg = sum/k;
                ans=max(ans,avg);
            }
        }

        return ans;
    }
};