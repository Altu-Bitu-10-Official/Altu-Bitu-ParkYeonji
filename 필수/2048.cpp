#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<char> arr(N, '\0');
    vector<bool> arr2(26, false);

    int S;
    char a;
    int I = 0;

    for (int i = 0; i < K; i++) {
        cin >> S >> a;

        I += S;
        I %= N;

        if (arr[I] != '\0') {
            if (arr[I] != a) {
                cout << "!" << endl;
                return 0;
            }
        }
        else {
            if (arr2[a - 'A']) {
                cout << "!" << endl;
                return 0;
            }
            arr[I] = a;
            arr2[a - 'A'] = true;
        }
    }

    for (int j = 0; j < N; j++) {
        if (arr[I] == '\0') cout << "?";
        else cout << arr[I];

        I--;
        if (I < 0) I += N;
    }

    return 0;
}


2048