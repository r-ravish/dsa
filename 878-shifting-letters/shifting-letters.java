class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        for(int i=shifts.length - 2; i>=0; i--){
            shifts[i] = (shifts[i] + shifts[i+1])%26;
        }

        String ans = "";

        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            char result = (char)('a' + (ch + shifts[i]-'a')%26);
            ans = ans + result;
        }

        return ans;
    }
}