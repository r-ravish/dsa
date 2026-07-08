class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }

            if(st.empty()){
                int j=1;
                int temp = -1;
                while((i+j)%nums.size() != i){
                    if(nums[(i+j)%nums.size()] > nums[i]){
                        temp = nums[(i+j)%nums.size()];
                        break;
                    }
                    j++;
                }
                ans.push_back(temp);
            }else{
                ans.push_back(st.top());
            }

            st.push(nums[i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};