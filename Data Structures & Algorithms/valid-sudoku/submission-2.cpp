class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> row, column;
        map<pair<int, int>, unordered_set<int>> square;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                int ele = board[i][j];
                  if (ele == '.') continue;
                pair<int, int> squarekey(i / 3, j / 3);

                if (row[i].count(ele) || column[j].count(ele) || square[squarekey].count(ele)) {
                    return false;
                }

                row[i].insert(ele);
                column[j].insert(ele);
                square[squarekey].insert(ele);

            }
        }

        return true;
    }
};
