class Solution
{
private:
    vector<vector<string>> res;
    unordered_set<int> cols, posDiag, negDiag;

    void backtrack(int row, int n, vector<string>& board)
    {
        if(row == n)
        {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++)
        {
            if(cols.count(c) || posDiag.count(row+c) || negDiag.count(row-c))
                continue;

            board[row][c] = 'Q';
            cols.insert(c); posDiag.insert(row+c); negDiag.insert(row-c);

            backtrack(row+1, n, board);

            board[row][c] = '.';
            cols.erase(c); posDiag.erase(row+c); negDiag.erase(row-c);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board);
        return res;
    }
};