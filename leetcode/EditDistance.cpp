class Solution {
public:
       int minDistance(string word1, string word2) {
        int length1 = word1.length();
        int length2 = word2.length();
        
        int step[length1+1][length2+1];
        memset(step, 0, sizeof(step));
        for(int i = 1; i <= length1; i++) {
            step[i][0] = i;
        }
        for(int j = 1; j <= length2; j++) {
            step[0][j] = j;
        }
        step[0][0] = 0;
        for(int x = 1; x <= length1; ++x) {
            for(int y = 1; y <= length2; ++y) {
                if(word1[x-1] == word2[y-1]) {
                    step[x][y] = step[x-1][y-1];
                }
                else {
                   step[x][y] = min(step[x-1][y], min(step[x-1][y-1], step[x][y-1])) + 1; 
                }
            }
        }
        return step[length1][length2];
    }
};
