class Solution {
public:
    void genPermutation(int ind, vector<int>& nums, int n, vector<vector<int>>& ans){
        if(ind >= n){
            ans.push_back(nums);
        }

        for(int i=ind; i<n; i++){
            swap(nums[ind], nums[i]);
            genPermutation(ind+1, nums, n, ans);
            swap(nums[ind], nums[i]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        genPermutation(0, nums, n, ans);

        return ans;
    }
};