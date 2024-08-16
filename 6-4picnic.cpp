#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> board;
int n;

// 대각선 검사 함수
bool goodBoard(int row, int col) {
    // 열 검사
    for (int i = 0; i < row; ++i) {
        if (board[i][col]) return false;
    }

    // 왼쪽 위에서 오른쪽 아래 대각선 검사
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) return false;
    }

    // 오른쪽 위에서 왼쪽 아래 대각선 검사
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j]) return false;
    }

    return true;
}

// N-Queen 문제를 해결하는 함수
void SetQueen(int row, int &count) {
    if (row == n) {
        count++;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (goodBoard(row, col)) {
            board[row][col] = true; // 퀸 배치
            SetQueen(row + 1, count); // 다음 행으로 이동
            board[row][col] = false; // 백트래킹: 퀸 제거
        }
    }
}

int main() {
    cin >> n;
    board.assign(n, vector<bool>(n, false)); // 체스판 초기화

    int count = 0;
    SetQueen(0, count);
    cout << count << endl;

    return 0;
}