class Solution {
    public int myAtoi(String s) {
        s = s.trim();
        int a = 0; 
        int sign = 1;
        long out=0;
        while(a != s.length()){
            if(s.charAt(a) == '-' && a == 0){
                sign = -1;
            }else if(s.charAt(a) == '+' && a == 0){
                sign = 1;
            }else if(Character.isDigit(s.charAt(a))) {
                int temp = s.charAt(a) - '0';
                out=out*10+temp;
                if(sign == 1 && out > Integer.MAX_VALUE){
                    return Integer.MAX_VALUE;
                }else if(sign == -1 && -out < Integer.MIN_VALUE){
                    return Integer.MIN_VALUE;
                }
                
            }else{
                break;
            }
            
            a++;
        }
        
        return (int)(sign * out);
        
    }
}