class Solution {
    public String reverseWords(String s) {
        String[] st = s.split(" ");
        String out = "";

        for(int i = st.length - 1; i>=0; i--){
            if(st[i] != ""){
                out+=st[i]+" ";
            }
        }

        return out.trim();
    }
}