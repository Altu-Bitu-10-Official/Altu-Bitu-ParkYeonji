#include <iostream>
#include <string>
using namespace std;

int main() {
    int M;
    cin >> M;

    int arr[21] = { 0 };

    for (int i = 0; i < M; i++) {
        string order;
        cin >> order;

        if (order == "add") {
            int x;
            cin >> x;
            arr[x] = 1;
        }
        else if (order == "remove") {
            int x;
            cin >> x;
            arr[x] = 0;
        }
        else if (order == "check") {
            int x;
            cin >> x;
            cout << arr[x] << '\n';
        }
        else if (order == "toggle") {
            int x;
            cin >> x;
            if (arr[x] == 1) arr[x] = 0;
            else arr[x] = 1;
        }
        else if (order == "all") {
            for (int j = 1; j <= 20; j++) {
                arr[j] = 1;
            }
        }
        else if (order == "empty") {
            for (int j = 1; j <= 20; j++) {
                arr[j] = 0;
            }
        }
    }

    return 0;
}