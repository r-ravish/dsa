class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n);
        for(int i=0; i<bookings.size(); i++){
            int left = bookings[i][0];
            int right = bookings[i][1];
            int add = bookings[i][2];

            answer[left-1]+=add;
            if(right < n){
                answer[right]-=add;
            }
            

        }

        for(int i=1; i<answer.size(); i++){
            answer[i]+=answer[i-1];
        }

        return answer;
    }
};