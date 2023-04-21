class Solution {
public:
    vector<vector<int> > MySudoku;
    bool checkSudoku(int& row, int& col)
    {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (MySudoku[i][j] == 0) {
                    row = i;
                    col = j;
                    return false;
                }
            }
        }
        return true;
    }
    bool inRow(int i, int num)
    {
        for (int j = 0; j < 9; j++) {
            if (MySudoku[i][j] == num)
                return false;
        }
        return true;
    }
    bool inCol(int j, int num)
    {
        for (int i = 0; i < 9; i++) {
            if (MySudoku[i][j] == num)
                return false;
        }
        return true;
    }
    bool inSmall(int row, int col, int num)
    {
        int rowfactor = row - (row % 3);
        int colfactor = col - (col % 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int item = MySudoku[i + rowfactor][j + colfactor];
                if (item == num)
                    return false;
            }
        }
        return true;
    }
    bool isPossibleToPut(int row, int col, int number)
    {
        bool r = inRow(row, number);
        bool c = inCol(col, number);
        bool s = inSmall(row, col, number);
        return r && c && s;
    }
    bool solve(vector<vector<int> >& MySudoku)
    {
        int row = 0;
        int col = 0;
        if (checkSudoku(row, col)) {
            return true;
        }
        for (int number = 1; number <= 9; number++) {
            if (isPossibleToPut(row, col, number)) {
                MySudoku[row][col] = number;
                if (solve(MySudoku))
                    return true;
                MySudoku[row][col] = 0;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char> >& board)
    {
        MySudoku.resize(9, vector<int>(9, 0));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    MySudoku[i][j] = (board[i][j] - '0');
                }
            }
        }
        solve(MySudoku);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = MySudoku[i][j] + '0';
                board[i][j] = ch;
            }
        }
        return;
    }
};
