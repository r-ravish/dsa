class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1 && flowerbed[0] == 0){
            return true;
        }

        int count = 0;
        for(int i=0; i<flowerbed.size(); i++){
            if(i==0){
                if(flowerbed[i] == 0 && flowerbed[i+1] != 1){
                    flowerbed[i] = 1;
                    count++;
                }
            }else if(i==flowerbed.size()-1){
                if(flowerbed[i] == 0 && flowerbed[i-1] != 1){
                    flowerbed[i] = 1;
                    count++;
                }
            }else{
                if(flowerbed[i] == 0 && flowerbed[i+1] == 0 && flowerbed[i-1] == 0){
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        if(count >= n){
            return true;
        }return false;
    }
};