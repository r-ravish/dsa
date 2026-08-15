class Solution {
public:
    void printCombinationSum(int ind, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans, int sum, int target, int n){
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<n; i++){
            if(i>ind && nums[i] == nums[i-1]) continue;
            if(nums[i] > target-sum) break;

            temp.push_back(nums[i]);
            sum+=nums[i];
            printCombinationSum(i+1, temp, nums, ans, sum, target, n);
            sum-=nums[i];
            temp.pop_back();
        }
    } 

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        int n = candidates.size();
        int sum=0;

        vector<int> temp;
        vector<vector<int>> ans;

        printCombinationSum(0, temp, candidates, ans, sum, target, n);

        return ans;
    }
};