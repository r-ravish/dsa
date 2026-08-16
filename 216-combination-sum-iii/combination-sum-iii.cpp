class Solution {
public:
    void findCombinationSum(int ind, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans, int target, int size, int& k){
        if(target==0){
            if(temp.size() == k) ans.push_back(temp);
            return;
        }

        for(int i=ind; i<size; i++){
            if(nums[i] > target) break;
            temp.push_back(nums[i]);
            findCombinationSum(i+1, temp, nums, ans, target-nums[i], size, k);
            temp.pop_back();
        }
    }
    

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        int size = 9;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};

        vector<vector<int>> ans;
        int sum = 0;

        findCombinationSum(0, temp, nums, ans, n, size, k);

        return ans;
    }
};