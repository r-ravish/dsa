class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        int ans = INT_MIN;
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int x = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int area = heights[x]*(nse-pse-1);
                ans = max(ans,area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int x = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int area = heights[x]*(nse-pse-1);
            ans = max(ans,area);
        }

        return ans;
    }
};