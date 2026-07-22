class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k==n){          // edge case
            return "0";
        }
        string out = "";
        stack<char> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() > num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k>0 && !st.empty()){
            k--;
            st.pop();
        }

        string res = "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        
        // logix ends edge cases starts

        int s = res.size();
        int z = 0;
        while(res[z] == '0'){
            z++;
        }
    
        int a = 0;
        int count=0;
        if(res[0] == '0'){
            while(a != res.size()){
                if(res[a] == '0'){
                    count++;
                }else{
                    break;
                }
                a++;
            }
        }

        if(count==res.size()){
            return "0";
        }

        return res.substr(z,s);
    }
};