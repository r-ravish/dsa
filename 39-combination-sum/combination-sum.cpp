class Solution {
public:
    void printCombinationSum(int ind, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans, int target, int sum, int n){
        if(sum > target) return;
        if(ind >= n){
            if(sum == target){
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back(nums[ind]);
        sum+=nums[ind];
        printCombinationSum(ind, temp, nums, ans, target, sum, n);

        temp.pop_back();
        sum-=nums[ind];
        printCombinationSum(ind+1, temp, nums, ans, target, sum, n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum=0;
        vector<int> temp;
        vector<vector<int>> ans;

        printCombinationSum(0, temp, candidates, ans, target, sum, n);

        return ans;
    }
};