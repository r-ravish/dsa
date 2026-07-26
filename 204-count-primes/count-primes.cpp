class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<int> temp(n, 1);
        for(int i=2; i*i<n; i++){
            if(temp[i] == 1){
                for(int j=i*i; j<n; j+=i){
                    temp[j] = -1;
                }
            }
        }

        for(int k=2; k<n; k++){
            if(temp[k] == 1){
                count++;
            }
        }

        return count;
    }
};