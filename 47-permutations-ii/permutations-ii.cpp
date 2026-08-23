class Solution {
public:
    void genPermutations(vector<int>& nums, vector<int>& temp, int n, unordered_map<int,int>& mpp, vector<vector<int>>& ans){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        unordered_set<int> used;


        for(int i=0; i<n; i++){
            if(used.count(nums[i])){
                continue;
            }
            
            if(mpp[nums[i]] > 0){
                temp.push_back(nums[i]);
                mpp[nums[i]]--;
                used.insert(nums[i]);
                genPermutations(nums, temp, n, mpp, ans);
                mpp[nums[i]]++;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> temp;
        vector<vector<int>> ans;

        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }

        genPermutations(nums, temp, n, mpp, ans);

        return ans;
    }
};