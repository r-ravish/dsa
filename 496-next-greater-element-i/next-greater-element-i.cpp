class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> out;
        stack<int> st;
        vector<int> ans;

        for(int i=nums2.size()-1; i>=0; i--){
            if(st.empty()){
                out[nums2[i]] = -1;
                st.push(nums2[i]);
            }else{
                while(!st.empty() && st.top() < nums2[i]){
                    st.pop();
                }
                
                if(st.empty()){
                    out[nums2[i]] = -1;
                }else{
                    out[nums2[i]] = st.top();
                }
                    
                st.push(nums2[i]);
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(out[nums1[i]]);
        }

        return ans;
    }
};