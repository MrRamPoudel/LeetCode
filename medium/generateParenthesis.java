/*
 So the number of close parenthesis < open for valid 
 and both open and close must equal n
 */

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        backtrack(res, 0,0,"", n);
        return res;
    }
     private void backtrack(List<String> res, int openN, int closeN, String s, final int n) {
            if(closeN == openN && closeN == n){
                res.add(s);
                return;
            }
            if(openN < n) {
                backtrack(res, openN+1, closeN, s+"(", n);
            }
            if(closeN < openN) {
                backtrack(res, openN, closeN+1, s+")", n);
            }
        }
}
