class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    int lenA = A.size();
    int lenB = B.size();
    int lens[lenA][lenB];
    int maxval = 0;
    memset(lens, 0, sizeof(int)*lenA*lenB);
    for(int i = 0; i < lenA; ++i){
      for(int j = 0; j < lenB; ++j){
        if(A[i] == B[j]){
          if(i-1 >=0 && j-1 >= 0){
            if(A[i-1]==B[j-1])
              lens[i][j] = 1 + lens[i-1][j-1];
            else
                lens[i][j] = 1;
          }        
          else{
             lens[i][j] = 1;
          }
        }
        else{
          int va = i-1 >= 0? lens[i-1][j] : 0;
          int vb = j-1 >= 0? lens[i][j-1] : 0;
          lens[i][j] = max(va, vb);
        }
        if(lens[i][j] > maxval)
          maxval = lens[i][j];
      }
    }
    return maxval;
  }
};
