class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int left = 0;
        int right = 0;
        while(right < nums2.size() && left < nums1.size()){
            if(nums1[left] < nums2[right]){
                left++;
            }else if(nums1[left] > nums2[right]){
                right++;
            }else{
                ans.insert(nums1[left]);
                left++;
                right++;
            }
        }

        vector<int> out;
        for(auto i : ans){
            out.push_back(i);
        }
        return out;
    }
};