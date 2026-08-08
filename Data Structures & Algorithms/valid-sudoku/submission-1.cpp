class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // rows
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> rhm;
            for (int j = 0; j < 9; j++) {
                char ele = board[i][j];
                if (ele != '.') {
                    if (rhm.count(ele) > 0) {
                        return false;
                    }
                    rhm[ele]++;
                }
            }
        }

        // columns
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> rhm;
            for (int j = 0; j < 9; j++) {
                char ele = board[j][i];
                if (ele != '.') {
                    if (rhm.count(ele) > 0) {
                        return false;
                    }
                    rhm[ele]++;
                }
            }
        }

        for (int square = 0; square < 9; square++) {
            unordered_map<char, int> shm;
            for (int i = 0; i < 3; i++) {
                
                for (int j = 0; j < 3; j++) {
                    int k = (square / 3) * 3 + i;
                    int l = (square % 3) * 3 + j;
                    char ele = board[k][l];
                    if (ele != '.') {
                        if (shm.count(ele) > 0) {
                            return false;
                        }
                        shm[ele]++;
                    }
                }
            }
        }

        return true;
    }
};
