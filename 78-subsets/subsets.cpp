class Solution {
public:
    vector<vector<int>> ans;
    void printSubsets(int ind, vector<int> temp, vector<int> nums, int n){
        if(ind >= n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        printSubsets(ind+1, temp, nums, n);
        temp.pop_back();
        printSubsets(ind+1, temp, nums, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        printSubsets(0, temp, nums, n);

        return ans;
    }
};