class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int j=i+1;
            int k=n-1;

            while(j<k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                    j++;
                    k--;
                }else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }else{
                    j++;
                }
            }
        }

        vector<vector<int>> out;
        for(auto i : ans){
            out.push_back(i);
        }

        return out;
    }
};