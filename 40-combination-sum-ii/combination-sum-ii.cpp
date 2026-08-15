class Solution {
public:
    void printCombinationSum(int ind, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans, int target, int n){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<n; i++){
            if(i>ind && nums[i] == nums[i-1]) continue;
            if(nums[i] > target) break;

            temp.push_back(nums[i]);
            printCombinationSum(i+1, temp, nums, ans, target-nums[i], n);
            temp.pop_back();
        }
    } 

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        int n = candidates.size();

        vector<int> temp;
        vector<vector<int>> ans;

        printCombinationSum(0, temp, candidates, ans, target, n);

        return ans;
    }
};