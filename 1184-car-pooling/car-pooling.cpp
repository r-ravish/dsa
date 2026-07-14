class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> answer(1001);
        for(int i=0; i<trips.size(); i++){
            int numPass = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            answer[from]+=numPass;
            answer[to]-=numPass;
        }

        for(int i=0; i<answer.size(); i++){
            if(i==0){
                if(answer[0] > capacity){
                    return false;
                }
            }else{
                answer[i]+=answer[i-1];
                if(answer[i] > capacity){
                    return false;
                }
            }
            
        }

        return true;
    }
};