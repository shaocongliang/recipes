import java.lang.Character;
class LengthOfLastWord {
    public int lengthOfLastWord( String s ) {
        boolean inWord = false;
        int     len    = 0;
        for ( int i = 0; i < s.length(); ++i ) {
            char ch = s.charAt( i );
            if ( inWord == true ) {
                if ( Character.isLetter( ch ) == true ) {
                    len++;
                } else {
                    inWord = false;
                }
            } else {
                if ( Character.isLetter( ch ) == false ) {
                    continue;
                } else {
                    // non-word --> word
                    len    = 1;
                    inWord = true;
                }
            }
        }
        return len;
    }
    public static void main( String[] args ) {
        String           s1               = new String( "" );
        String           s2               = new String( "abc   a " );
        String           s3               = new String( "   abc   a " );
        String           s4               = new String( "abc   a" );
        String           s5               = new String( "    ab#" );
        LengthOfLastWord lengthOfLastWord = new LengthOfLastWord();
        System.out.println( lengthOfLastWord.lengthOfLastWord( s1 ) );
        System.out.println( lengthOfLastWord.lengthOfLastWord( s2 ) );
        System.out.println( lengthOfLastWord.lengthOfLastWord( s3 ) );
        System.out.println( lengthOfLastWord.lengthOfLastWord( s4 ) );
        System.out.println( lengthOfLastWord.lengthOfLastWord( s5 ) );
    }
}