class Solution {
public:
    void getPermutations(int ind, vector<int>& nums, vector<vector<int>>& ans, int n){
        if(ind >= n){
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for(int i=ind; i<n; i++){
            if(used.count(nums[i])){
                continue;
            }
            used.insert(nums[i]);
            swap(nums[ind], nums[i]);
            
            getPermutations(ind+1, nums, ans, n);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        getPermutations(0, nums, ans, n);

        return ans;
    }
};