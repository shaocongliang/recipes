class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        TreeMap<Integer, Stack<Integer>> am = new TreeMap<>();
        for(int i = 0; i < A.length; ++i){
            if(am.containsKey(A[i])){
                Stack<Integer> s = am.get(A[i]);
                s.push(i);
                am.put(A[i], s);
            }
            else {
                Stack<Integer> s = new Stack<>();
                s.push(i);
                am.put(A[i], s);
            }
        }
        for(int i = 0; i < B.length; ++i){
            Map.Entry<Integer, Stack<Integer>> sb = am.higherEntry(B[i]);
            if(sb != null){
                sb.getValue().pop();
                A[i] = sb.getKey();
                if(sb.getValue().size() == 0){
                    am.remove(sb.getKey());
                }
            }
            else{
                int min = Collections.min(am.keySet());
                am.get(min).pop();
                if(am.get(min).empty()){
                    am.remove(min);
                }
                A[i] = min;
            }
        }
        return A;
    }
}
