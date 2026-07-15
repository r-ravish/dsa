class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> out;
        int left = 0;
        int right = 0;
        while(left < m && right < n){
            if(nums1[left] <= nums2[right]){
                out.push_back(nums1[left]);
                left++;
            }
            else{
                out.push_back(nums2[right]);
                right++;
            }
        }

        while(left < m){
            out.push_back(nums1[left]);
            left++;
        }

        while(right < n){
            out.push_back(nums2[right]);
            right++;
        }

        nums1 = out;
    }
};