class Solution {
public:
    string ans = "";
    int sign = 1;
    long long converttoINT(string s){
        long long ans = 0;
        for(int i=0; i<s.size(); i++){
            char ch = s[i]-'0';
            ans=ans*10+(int)ch;

            if(sign > 0 && ans>=INT_MAX){
                return INT_MAX;
            }else if(sign<0 && sign*ans<=INT_MIN){
                return INT_MIN;
            }
        }

        return ans;
    }

    string Atoi(string s, int i){        
        if(i == s.size()){
            return ans;
        }
        if(i==0 && s[i] == '-'){
            sign = -1;
        }else if(i==0 && s[i] == '+'){
            sign = 1;
        }else if (s[i] >= '0' && s[i] <= '9'){
            ans+=s[i];
        }else{
            return ans;
        }

        return Atoi(s, i+1);
    }

    int myAtoi(string s) {
        int t = 0;
        for(int k=0; k<s.size(); k++){
            if(s[k] == ' '){
                t++;
            }else{
                break;
            }
        }

        string newS = s.substr(t);

        string out = Atoi(newS, 0);
        if(out == "") return 0;

        long long a = converttoINT(out);
        
        if(sign < 0) a=-a;

        return a;
    }
};