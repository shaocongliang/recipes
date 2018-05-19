public class Solution {
    public boolean canJump( int[] nums ) {
        if ( nums.length == 1 ) {
            return true;
        }
        int     nstep    = nums[ 0 ];
        int     l        = 0;
        int     r0       = nstep;
        int     foo      = 0;
        boolean newRange = false;
        while ( true ) {
            if ( l + nums[ l ] >= nums.length - 1 ) {
                return true;
            }
            if ( nums[ l ] == 0 && nstep == 0 ) {
                return false;
            }
            for ( int j = l + 1; j < nums.length && j <= l + nstep; ++j ) {
                int r1 = j + nums[ j ];
                if ( r1 >= ( nums.length - 1 ) ) {
                    return true;
                } else if ( r1 >= ( l + nstep ) ) {
                    newRange = true;
                    if ( ( j - l + nums[ j ] - nums[ l ] ) > foo ) {
                        foo = j - l + nums[ j ] - nstep;
                    }
                }
            }
            if ( newRange == false ) {
                l += nstep;
                nstep = nums[ l ];
            } else {
                l += nstep;
                nstep = foo;
            }
            foo      = 0;
            newRange = false;
        }
    }
}
