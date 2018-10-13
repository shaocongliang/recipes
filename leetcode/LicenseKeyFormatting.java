class Solution {
    private char toUpper(char c) {
        if (Character.isLetter(c))
            return Character.toUpperCase(c);
        return c;
    }

    public String licenseKeyFormatting(String S, int K) {
        String newFmt = new String();
        S = S.replace("-", "");
        if (K == 1) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < S.length(); ++i) {
                char c = toUpper(S.charAt(i));
                sb.append(c);
                if (i != S.length()-1)
                    sb.append('-');
            }
            return sb.toString();
        }
        if (S.length() <= K) {
            for (char c : S.toCharArray()) {
                newFmt += toUpper(c);

            }
            return newFmt;
        }
        int mod = S.length() % K;
        String sb = S.substring(0, mod);
        if (mod != 0) {
            for (char c : sb.toCharArray())
                newFmt += toUpper(c);
            newFmt += "-";
        }
        char c = 0;
        for (int i = mod; i < S.length(); ++i) {
            newFmt = newFmt + toUpper(S.charAt(i));
            if ((i - mod + 1) % K == 0 && (i != S.length() - 1))
                newFmt += '-';

        }
        return newFmt;
    }
}

