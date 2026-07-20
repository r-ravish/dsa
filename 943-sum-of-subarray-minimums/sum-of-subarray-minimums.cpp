class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(!st.empty()){
                nse[i] = st.top();
            }

            st.push(i);

        }
        
        vector<int> pse(n, -1);
        st = stack<int>();
        for(int i = 0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            if(!st.empty()){
                pse[i] = st.top();
            }

            st.push(i);
        }


        int mod = 1e9 + 7;
        long long total = 0;
        for(int i=0; i<arr.size(); i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (1LL*left*right*arr[i])%mod)%mod;
        } 
        return total%mod;
    }
};