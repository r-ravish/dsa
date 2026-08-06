class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=cardPoints[i];
        }

        int left = 0;
        int tempSum=0;
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            tempSum+=cardPoints[i];
            while(n-k < i-left+1){
                tempSum-=cardPoints[left];
                left++;
            }

            if(n-k == i-left+1){
                ans = max(ans, sum-tempSum);
            }
        }

        return ans;
    }
};