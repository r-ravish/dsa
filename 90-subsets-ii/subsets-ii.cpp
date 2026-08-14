class Solution {
public:
    void printSubsets(int ind, vector<int>& temp, vector<int>& nums, int n, set<vector<int>>& ans){
        if(ind >= n){
            ans.insert(temp);
            return;
        }

        temp.push_back(nums[ind]);
        printSubsets(ind+1, temp, nums, n, ans);
        temp.pop_back();
        printSubsets(ind+1, temp, nums, n, ans);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        vector<int> temp;

        printSubsets(0, temp, nums, n, ans);

        vector<vector<int>> out;
        for(auto i : ans){
            out.push_back(i);
        }

        return out;
    }
};