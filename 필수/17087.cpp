#include <iostream>
#include <vector>
using namespace std;

int gcdIter(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{
    int N, S;
    cin >> N >> S;

    vector<int> place(N);

    for (int i = 0; i < N; i++) {
        cin >> place[i];
        place[i] = abs(place[i] - S);
    }

    int min_D = 0;
    int D = place[0];

    for (int j = 1; j < N; j++) {
        D = gcdIter(D, place[j]);
    }

    cout << D;

    return 0;
}