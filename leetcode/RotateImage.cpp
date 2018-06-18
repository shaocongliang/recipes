class Solution {
public:
    void replace(std::vector<vector<int>> &matrix, std::vector<std::vector<bool>> &state, int i, int j, int val) {
        if(state[i][j] == false) {
            int ii = j;
            int jj = matrix.size() - i -1;
            replace(matrix, state, ii, jj, matrix[i][j]);
            matrix[i][j] = val;
            state[i][j] = true;
        }
        else {
            matrix[i][j] = val;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        std::vector<std::vector<bool>> state;
        state.resize(N);
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                state[i].push_back(false);
            }
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(state[i][j] == false) {
                    state[i][j] = true;
                    int ii = j;
                    int jj = N - i -1;
                    int val = matrix[i][j];
                    replace(matrix, state, ii, jj, val);
                }
            }
        }
    }
};