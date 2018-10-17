class Solution {
    private static String C = "C";
    private static String D = "D";
    private static String PLUS = "+";
    private int getLastValidRound(String[] ops, int pos, Stack<Integer> cs){
       for(;pos >= 0; pos--){
           if(ops[pos].equals(C) || ops[pos].equals(D) || ops[pos].equals(PLUS)){
                cs.push(pos);
                continue;
           }
           else{
               cs.pop();
               if(cs.empty()){
                   return pos;
               }
           }
       }
       return 0;
    }
    public int calPoints(String[] ops) {
        Stack<Integer> cs = new Stack<>();
        int score = 0;
        for(int i = 0; i < ops.length; ++i){
            if(ops[i].equals(C)){
                int index = getLastValidRound(ops, i, cs);
                score -= Integer.parseInt(ops[index]);
            } else if(ops[i].equals(D)){
                int index = getLastValidRound(ops, i, cs);
                score += Integer.parseInt(ops[index])*2;
                ops[i] = Integer.toString(Integer.parseInt(ops[index])*2);
            } else if(ops[i].equals(PLUS)){
                int index = getLastValidRound(ops, i, cs);
                int v1 = Integer.parseInt(ops[index]);
                cs.push(i);
                index = getLastValidRound(ops, index-1, cs);
                int v2 = Integer.parseInt(ops[index]);
                score += v1 + v2;
                ops[i] = Integer.toString(v1+v2);
            }
            else {
                score += Integer.parseInt(ops[i]);
            }
        }
        System.out.println(score);
        return score;
    }
}
