class Solution {
public:
    int maxofArr(vector<int>& nums){
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }

        return maxi;
    }
    int thirdMax(vector<int>& nums) {
        

        vector<int> temp;
        int firstMax = maxofArr(nums);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != firstMax){
                temp.push_back(nums[i]);
            }
        }

        nums=temp;
        temp.clear();
        int secondMax = maxofArr(nums);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != secondMax){
                temp.push_back(nums[i]);
            }
        }

        int ans = maxofArr(temp);
        bool a = false;
        for(auto i : temp){
            if(ans == i){
                a=true;
                break;
            }
          
        }

        
        if(ans == -2147483648 && a==false) return firstMax;
        return ans;
    }
};