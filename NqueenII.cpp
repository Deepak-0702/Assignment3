#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;

    // Helper function to perform backtracking
    void solve(int row, int n, vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
                continue; 

            // Place queen
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

            solve(row + 1, n, cols, diag1, diag2);

            // Backtrack
            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        board.assign(n, string(n, '.'));
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);

        solve(0, n, cols, diag1, diag2);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    Solution sol;
    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "\nAll possible N-Queens solutions:\n";
    for (auto &board : solutions) {
        for (auto &row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
