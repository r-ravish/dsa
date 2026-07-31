class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixMul;
        vector<int> suffixMul = nums;
        int mul = 1;
        for(int i=0; i<nums.size(); i++){
            prefixMul.push_back(mul);
            mul=mul*nums[i];
        }
        mul=1;
        for(int i=nums.size()-1; i>=0; i--){
            suffixMul[i] = mul;
            mul=mul*nums[i];
        }

        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            ans.push_back(prefixMul[i]*suffixMul[i]);
        }

        return ans;
    }
};