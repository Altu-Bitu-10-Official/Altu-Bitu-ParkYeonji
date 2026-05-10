#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> speed(n);

    for (int i = 0; i < n; i++) {
        cin >> speed[i];
    }

    int vn = speed[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (vn % speed[i] != 0) {
            vn = (vn / speed[i] + 1) * speed[i];
        }
    }

    cout << vn;

    return 0;
}