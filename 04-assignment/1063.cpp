#include <iostream>
#include <string>
using namespace std;

bool check(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) return false;
    return true;
}

int main() {
    string king, rock;
    int N;
    cin >> king >> rock >> N;

    int x = king[0] - 'A';
    int y = king[1] - '1';

    int p = rock[0] - 'A';
    int q = rock[1] - '1';

    for (int i = 0; i < N; i++) {
        string order;
        cin >> order;

        int dx = 0;
        int dy = 0;

        if (order == "R") {
            dx = 1;
        }
        else if (order == "L") {
            dx = -1;
        }
        else if (order == "B") {
            dy = -1;
        }
        else if (order == "T") {
            dy = 1;
        }
        else if (order == "RT") {
            dx = 1;
            dy = 1;
        }
        else if (order == "LT") {
            dx = -1;
            dy = 1;
        }
        else if (order == "RB") {
            dx = 1;
            dy = -1;
        }
        else if (order == "LB") {
            dx = -1;
            dy = -1;
        }

        int nx = x + dx;
        int ny = y + dy;

        if (!check(nx, ny)) continue;

        if (nx == p && ny == q) {
            int np = p + dx;
            int nq = q + dy;

            if (!check(np, nq)) continue;

            p = np;
            q = nq;
        }

        x = nx;
        y = ny;
    }

    cout << char(x + 'A') << char(y + '1') << '\n';
    cout << char(p + 'A') << char(q + '1') << '\n';

    return 0;
}