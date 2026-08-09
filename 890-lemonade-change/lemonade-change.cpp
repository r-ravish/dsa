class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        if(bills[0] != 5){
            return false;
        }

        int ten = 0;
        int five = 0;

        for(int i=0; i<n; i++){
            if(bills[i] == 5) five++;
            if(bills[i] == 10){
                ten++;
                if(five < 1){
                    return false;
                }else{
                    five--;
                }
            }else if(bills[i] == 20){
                if(five >= 1 && ten>=1){
                    five--;
                    ten--;
                }else{
                    if(five < 3){
                        return false;
                    }else{
                        five-=3;
                    }
                }
            }
        }

        return true;
    }
};