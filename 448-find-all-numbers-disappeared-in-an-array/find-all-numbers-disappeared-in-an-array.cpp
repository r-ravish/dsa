class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> temp(n+1, 0);
        for(int i=0; i<nums.size(); i++){
            temp[nums[i]]++;
        }

        for(int i=1; i<=n; i++){
            if(temp[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};