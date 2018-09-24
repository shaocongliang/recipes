class Solution {
    public char findTheDifference(String s, String t) {
        Map wordfeq = new HashMap<Character, Integer>();
        for(int i = 0; i < s.length(); ++i) {
            if(wordfeq.containsKey(s.charAt(i))) {
                int noccur = (int)wordfeq.get(s.charAt(i));
                wordfeq.put(s.charAt(i), noccur+1);
            }
            else {
                wordfeq.put(s.charAt(i), 1);
            }
        }
        char[] tcs = t.toCharArray();
        for(char ch : tcs) {
            if(wordfeq.containsKey(ch) == false)
                return ch;
            else{
                if((int)wordfeq.get(ch) == 0) {
                    return ch;
                }
                else {
                    int noccur = (int)wordfeq.get(ch);
                    wordfeq.put(ch, noccur-1);
                }
            }
        }
        return 0;
    }
}