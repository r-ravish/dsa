class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }else{
                nse[i] = n;
            }st.push(i);
        }

        st = stack<int>();

        vector<int> pse(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }else{
                pse[i] = -1;
            }st.push(i);
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int area = heights[i]*(nse[i] - pse[i]-1);
            ans=max(ans, area);
        }

        return ans;

    }
};