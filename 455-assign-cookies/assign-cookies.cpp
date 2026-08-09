class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<int> temp;

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }


        for(int i=low; i<=high; i++){
            nums[i] = temp[i - low];
        }
    }

    void divide(vector<int>& nums, int low, int high){
        if(low >= high){
            return;
        }
        int mid = low + (high-low)/2;
        divide(nums, low, mid);
        divide(nums, mid+1, high);

        merge(nums, low, mid, high);
    }

    void mergeSort(vector<int>& nums, int low, int high){
        divide(nums, low, high);
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        mergeSort(g, 0, n-1);
        mergeSort(s, 0, m-1);

        int left = 0;
        int right = 0;
        while(left < n && right < m){
            if(s[right] >= g[left]){
                left++;
                right++;
            }else if(s[right] < g[left]){
                right++;
            }
        }

        return left;
    }
};