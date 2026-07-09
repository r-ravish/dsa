class NumArray {
public:
    vector<int> numArray;
    NumArray(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++){
            nums[i] = nums[i-1] + nums[i];
        }
        numArray = nums;
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return numArray[right];
        }
        return numArray[right]-numArray[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */