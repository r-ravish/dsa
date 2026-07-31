class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int ans = 0;
        int i=0;
        while(i < cardPoints.size()){
            sum+=cardPoints[i];
            i++;
        }

        int left = 0;
        int tempSum = 0;
        for(int i=0; i<n; i++){
            tempSum+=cardPoints[i];
            while(i-left+1 > n-k){
                tempSum-=cardPoints[left];
                left++;
            }
            if(i-left+1 == n-k){
                ans = max(ans, sum-tempSum);
            }
        }

        return ans;
    }
};