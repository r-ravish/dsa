class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size()-1;
        int count=0;

        while(left<=right){
            if(nums[left] == val){
                if(nums[right] != val){
                    swap(nums[left], nums[right]);
                }
                else{
                    right--;
                }
            }else{
                left++;
                count++;
            }
        }

        return count;
    }
};