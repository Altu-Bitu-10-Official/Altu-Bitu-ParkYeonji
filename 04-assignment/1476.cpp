#include <iostream>
using namespace std;

int main() {
    int E, S, M;
    cin >> E >> S >> M;

    int year = 1;

    while (true) {
        int e = year % 15;
        int s = year % 28;
        int m = year % 19;

        if (e == 0) e = 15;
        if (s == 0) s = 28;
        if (m == 0) m = 19;

        if (e == E && s == S && m == M) {
            cout << year;
            break;
        }

        year++;
    }

    return 0;
}