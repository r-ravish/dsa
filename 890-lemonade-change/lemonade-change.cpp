class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5){
            return false;
        }

        unordered_map<int,int> mpp;

        for(int i=0; i<bills.size(); i++){
            mpp[bills[i]]++;

            if(bills[i] == 10){
                if(mpp[5] < 1){
                    return false;
                }else{
                    mpp[5]--;
                }
            }else if(bills[i] == 20){
                if(mpp[5] >= 1 && mpp[10]>=1){
                    mpp[5]--;
                    mpp[10]--;
                }else{
                    if(mpp[5] < 3){
                        return false;
                    }else{
                        mpp[5]-=3;
                    }
                }
            }
        }

        return true;
    }
};