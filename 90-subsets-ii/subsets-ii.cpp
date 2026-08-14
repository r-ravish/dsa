class Solution {
public:
    void printSubsets(int ind, vector<int>& temp, vector<int>& nums, int n, vector<vector<int>>& ans){
        ans.push_back(temp);

        for(int i=ind; i<nums.size(); i++){
            if(i>ind && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            printSubsets(i+1, temp, nums, n, ans);
            temp.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;

        printSubsets(0, temp, nums, n, ans);

        return ans;
    }
};