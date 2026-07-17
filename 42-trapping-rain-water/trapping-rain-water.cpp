class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> suffixMax(n, -1);
        suffixMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }

        int total = 0;
        int leftMax = height[0];
        for(int i=0; i<n; i++){
            leftMax = max(height[i], leftMax);
            if(height[i] < leftMax && height[i] < suffixMax[i]){
                total+=min(leftMax, suffixMax[i])-height[i];
            }
        }


        return total;
    }
};