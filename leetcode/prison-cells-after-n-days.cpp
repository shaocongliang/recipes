class Solution {
 public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    const int PERIOD = 14;
    N %= PERIOD;
    if(N == 0) N = 14;
    for(int i = 0; i < N; ++i){
      vector<int> v;
      v.resize(8);
      v[0] = 0;
      v[7] = 0;
      for(int i = 1; i <= 6; ++i) {
        if(cells[i-1] == cells[i+1]) {
          v[i] = 1;
        }else {
          v[i] = 0;
        }
      }
      cells = v;
    }
    return cells;
  }
};
