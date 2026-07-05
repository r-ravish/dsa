class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int ones = 0;
        int two = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zero++;
            }else if(nums[i] == 1){
                ones++;
            }else{
                two++;
            }
        }

        int index=0;
        int a = 0;
        while(a != zero){
            nums[index] = 0;
            a++;
            index++;
        }
        a=0;
        while(a != ones){
            nums[index] = 1;
            a++;
            index++;
        }
        a = 0;
        while(a != two){
            nums[index] = 2;
            a++;
            index++;
        }
    }
};