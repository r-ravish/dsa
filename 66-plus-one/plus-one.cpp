class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        int temp = -1;
        while(n >= 0){
            if(digits[n] < 9){
                digits[n]++;
                return digits;
            }else{
                temp = n;
                digits[n]=0;
                n--;
            }
        }

        digits.push_back(1);
        int a = digits[digits.size()-1];
        digits[digits.size()-1] = digits[temp];
        digits[temp] = a;
        return digits;

    }
};