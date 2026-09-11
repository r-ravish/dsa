class Solution {
public:
    void printSubsets(int ind, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int n){
        if(ind >= n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        printSubsets(ind+1, nums, temp, ans, n);
        temp.pop_back();
        printSubsets(ind+1, nums, temp, ans, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;

        printSubsets(0, nums, temp, ans, n);

        return ans;
    }
};