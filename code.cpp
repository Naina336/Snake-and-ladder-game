#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find the minimum number of moves to reach the last cell
int minMovesToReachEnd(vector<int>& board) {
    int n = board.size();
    vector<int> minMoves(n, INT_MAX);  // DP array to store the minimum moves to reach each cell
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);  // Start from the first cell
    minMoves[0] = 0;
    visited[0] = true;

    while (!q.empty()) {
        int pos = q.front();
        q.pop();

        // Try moving from pos by rolling the dice (1 to 6)
        for (int dice = 1; dice <= 6; ++dice) {
            int nextPos = pos + dice;

            if (nextPos < n) {
                // If there's a snake or ladder, move to its destination
                if (board[nextPos] != -1) {
                    nextPos = board[nextPos];
                }

                // If this path is better, update the DP array
                if (minMoves[nextPos] > minMoves[pos] + 1) {
                    minMoves[nextPos] = minMoves[pos] + 1;
                    if (!visited[nextPos]) {
                        visited[nextPos] = true;
                        q.push(nextPos);
                    }
                }
            }
        }
    }

    return minMoves[n - 1] == INT_MAX ? -1 : minMoves[n - 1];  // If it's not possible to reach the last cell
}

int main() {
    int n = 30;
    vector<int> board(n, -1);

    // Add ladders
    board[2] = 21;
    board[4] = 7;
    board[10] = 25;
    board[19] = 28;

    // Snakes
    board[26] = 0;
    board[20] = 8;
    board[16] = 3;
    board[18] = 6;

    cout << "Minimum number of moves to reach the end: " << minMovesToReachEnd(board) << endl;

    return 0;
}
