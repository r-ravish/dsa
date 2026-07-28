class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int left = 0;
        int right = nums.size()-1;

        while(left <= right){
            long long leftsq = 1LL * nums[left]*nums[left];
            long long rightsq = 1LL * nums[right]*nums[right];

            if(leftsq >= rightsq){
                ans.push_back(leftsq);
                left++;
            }else{
                ans.push_back(rightsq);
                right--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};