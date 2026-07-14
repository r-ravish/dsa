class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int count=0;
        mp[0]=1; // Why do we need this? Try using [3] as an example with k = 3 
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(mp.contains(sum-k)){
                count+=mp[sum-k];
            }
            mp[sum]++;
        }

        return count;
    }
};