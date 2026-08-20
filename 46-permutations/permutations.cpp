class Solution {
public:
    void genPermutations(vector<int>& nums, vector<int> temp, vector<vector<int>>& ans, unordered_map<int,bool>& mpp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(mpp.contains(nums[i])) continue;

            temp.push_back(nums[i]);
            mpp[nums[i]] = true;
            genPermutations(nums, temp, ans, mpp);
            temp.pop_back();
            mpp.erase(nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp; 
        vector<vector<int>> ans;
        unordered_map<int,bool> mpp;
        genPermutations(nums, temp, ans, mpp);

        return ans;
    }
};