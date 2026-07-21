class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> pge(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                pge[i] = st.top();
            }else{
                pge[i] = -1;
            }st.push(i);
        }
        
        vector<int> nge(n);
        st = stack<int>();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i] = st.top();
            }else{
                nge[i] = n;
            }st.push(i);
        }
        long long max = 0;
        for(int i=0; i<n; i++){
            int right = nge[i] - i;
            int left = i-pge[i];
            max = max + (1LL * left * right * nums[i]);
        }

        vector<int> pse(n);
        st = stack<int>();
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }else{
                pse[i] = -1;
            }st.push(i);
        }
        
        vector<int> nse(n);
        st = stack<int>();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }else{
                nse[i] = n;
            }st.push(i);
        }

        long long min = 0;
        for(int i=0; i<nums.size(); i++){
            int left = i-pse[i];
            int right = nse[i] - i;
            min=min+(1LL*left*right*nums[i]);
        }



        return max-min;
    }
};