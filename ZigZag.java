class ZigZag {

    public static void main( String[] args ) {
        String str  = "PAY";
        int    T    = 2 * numRows - 2; // 周期长度
        int    clen = numRows - 1;     // 每个周期列数
        int[][] foo = new int[ numRows ][ ( str.length() / T + 1 ) * clen ];
        for ( int i = 0; i < str.length(); ++i ) {
            int ct = i / T; // 当前周期
            int ii = i - i / T * T;
            if ( ii / numRows == 0 ) {
                int row          = ii / numRows;
                int col          = ct * clen;
                foo[ ii ][ col ] = str.charAt( i );
            }
            if ( ii / numRows == 1 ) {
                int row           = numRows - ( ii + 1 ) % numRows - 1;
                int col           = ii % numRows + 1 + ( ct * clen );
                foo[ row ][ col ] = str.charAt( i );
            }
        }
        for ( int i = 0; i < foo.length; ++i ) {
            for ( int j = 0; j < foo[ i ].length; ++j ) {
                if ( foo[ i ][ j ] != 0 ) {
                }
            }
        }
        str.System.out.println();
    }
}