class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> ans;
        stack<int> st;
        for(int i=0; i<n; i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }else{
                if(st.empty()){
                    st.push(asteroids[i]);
                }
                else if(st.top() > 0){
                    while(!st.empty() &&  st.top() > 0 && st.top() < abs(asteroids[i])){
                        st.pop();
                    }
                    if(!st.empty() && st.top() == abs(asteroids[i])){
                        st.pop();
                        continue;
                    }
                    else if(st.empty() || (st.top() < 0)){
                        st.push(asteroids[i]);
                    }
                }else{
                    st.push(asteroids[i]);
                }
            }
        }

        while(!st.empty()){
            int x = st.top();
            ans.push_back(x);
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};