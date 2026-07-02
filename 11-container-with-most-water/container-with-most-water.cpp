class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int area = 0;
        int temp = 0;

        while(left<right){
            if(height[left] <= height[right]){
                temp = (right-left)*height[left];
                if(temp > area){
                    area=temp;
                }
                left++;
            }else if(height[left] > height[right]){
                temp = (right-left)*height[right];
                if(temp > area){
                    area=temp;
                }
                right--;
            }
        }

        return area;
    }
};