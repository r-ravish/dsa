class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> s;
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%k == 0){
                s.insert(nums[i]);
            }

            if(nums[i] > maxi){
                maxi = nums[i];
            }
        }

        for(int i=k; i<=maxi+k; i+=k){
            if(!s.contains(i)) return i;
        }

        return 0;

    }
};