class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int> mp;
        int out=0;
        mp[0] = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                sum-=1;
            }else{
                sum+=1;
            }

            if(mp.contains(sum) && i-mp[sum] >= out){
                out = i-mp[sum];
            }

            if(!mp.contains(sum)){
                mp[sum] = i;
            }
        }

        return out;
    }
};