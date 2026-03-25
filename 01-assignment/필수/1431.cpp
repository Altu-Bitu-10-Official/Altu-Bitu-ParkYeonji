#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int sumNum(const string& a) {
    int sum = 0;
    for (int k = 0; k < a.size(); k++) {
        if (isdigit(a[k])) {
            sum += a[k] - '0';
        }
    }
    return sum;
}


bool comp(const string& a, const string& b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    if (sumNum(a) != sumNum(b)) {
        return sumNum(a) < sumNum(b);
    }
    return a < b;
}


int main()
{
    int N;
    cin >> N;

    vector<string> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), comp);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}