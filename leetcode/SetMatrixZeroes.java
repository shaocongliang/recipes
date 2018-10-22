class Solution {
    public void setZeroes(int[][] matrix) {
        Set<Integer> row = new HashSet<>();
        Set<Integer> col = new HashSet<>();
        for(int i = 0; i < matrix.length; ++i){
            for(int j = 0; j < matrix[i].length; ++j){
                if(matrix[i][j] == 0){
                    row.add(i);
                    col.add(j);
                }
            }
        }
        Iterator iter = row.iterator();
        while(iter.hasNext()){
            int n = (int)iter.next();
            for(int j = 0; j < matrix[0].length; ++j){
                matrix[n][j] = 0;
            }
        }
        iter = col.iterator();
        while(iter.hasNext()){
            int n = (int)iter.next();
            for(int j = 0; j < matrix.length; ++j){
                matrix[j][n] = 0;
            }
        }
    }
}
