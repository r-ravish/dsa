class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n);
        for(int i=0; i<bookings.size(); i++){
            int left = bookings[i][0];
            int right = bookings[i][1];
            int add = bookings[i][2];

            while(left<=right ){
                answer[left-1]+=add;
                left++;
            }
        }

        return answer;
    }
};