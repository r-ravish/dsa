class Solution {
public:
    void printSubsets(int ind, vector<int>& temp, vector<int>& nums, int n, vector<vector<int>>& ans){
        if(ind >= n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        printSubsets(ind+1, temp, nums, n, ans);
        temp.pop_back();
        printSubsets(ind+1, temp, nums, n, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        printSubsets(0, temp, nums, n, ans);

        return ans;
    }
};