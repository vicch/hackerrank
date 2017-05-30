// Problem:
// A chessboard's rows are numbered from 1 to n, going from bottom to top; its
// columns are numbered from 1 to n, going from left to right. Each square on
// the board is denoted by a tuple (r, c), describing the row r, and column c.
// In a single move, the queen can attack any square in any of the 8 directions
// (left, right, up, down, or the four diagonals). There are k obstacles on the
// chessboard preventing the queen from attacking any square that has an
// obstacle blocking the the queen's path to it. Given the queen's position and
// the locations of all the obstacles, find and print the number of squares the
// queen can attack from her position.
// 
// Example:
// Input: 4 0 (board size and number of obstacles)
//        4 4 (queen's position)
//        ... (each obstacle's position)
// Output: 9
// 
// Solution:
// Only obstacles on 8 directions to the queen are meaningful, and only those
// that are closest to the queen decides the range the queen can move to. Find
// out closest obstacles on 8 directions and add up the distances from queen
// to each of them. Obstacles are initialized as out of the border of the board.
// 
// Direction IDs:
// 7 0 1
// 6 x 2
// 5 4 3
 
#include <iostream>

using namespace std;

// Determine the direction of one coord to another
// Input values are coord diffs
int dir(int rd, int cd) {
    if (rd == 0) return cd > 0 ? 2 : 6;
    if (cd == 0) return rd > 0 ? 0 : 4;
    if (rd == cd) return rd > 0 ? 1 : 5;
    if (rd == -cd) return rd > 0 ? 7 : 3;
    return -1;
}

// Calculate distance between 2 coords
// Assuming 2 coords are on same row, or column or 
int dist(int r1, int c1, int r2, int c2) {
    if (r1 == r2) return abs(c1 - c2) - 1;
    return abs(r1 - r2) - 1;
}

int main() {
    int n, k, qr, qc, r, c, d, i;

    // Input board size, number of obstacles and (r, c) for queen
    cin >> n >> k >> qr >> qc;

    // Initial obstacles as out of board positions on 8 directions
    int b[8][2] = {
        {n + 1, qc},
        {(qr > qc ? n + 1 : qr + (n + 1 - qc)), (qr > qc ? qc + (n + 1 - qr) : n + 1)},
        {qr, n + 1},
        {(qr + qc > n + 1 ? qr - (n + 1 - qc) : 0), (qr + qc > n + 1 ? n + 1 : qc + qr)},
        {0, qc},
        {(qr > qc ? qr - qc : 0), (qr > qc ? 0 : qc - qr)},
        {qr, 0},
        {(qr + qc > n + 1 ? n + 1 : qr + qc), (qr + qc > n + 1 ? qc - (n + 1 - qr) : 0)}
    };

    for (; k > 0; k--) {
        // Input each obstacle's (r, c)
        cin >> r >> c;
        d = dir(r - qr, c - qc);
        // If obstacle is on one of 8 directions to queen
        if (d != -1)
            // If obstacle is closer to queen than the current obstacle on this direction
            if (dist(qr, qc, r, c) < dist(qr, qc, b[d][0], b[d][1]))
                b[d][0] = r, b[d][1] = c;
    }

    // Accumulate distance on 8 directions from queen to the obstacle on that direction
    for (d = i = 0; i < 8; i++)
        d += dist(qr, qc, b[i][0], b[i][1]);

    cout << d << endl;

    return 0;
}