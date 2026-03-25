#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countNum(int N, int k, string& s) {
    vector<string> ans;
    string str = "";
    int count = 1;

    for (int j = 0; j < N - k + 1; j++) {
        str = s.substr(j, k);
        ans.push_back(str);
    }

    sort(ans.begin(), ans.end());

    for (int m = 0; m < N - k; m++) {
        if (ans[m] != ans[m + 1]) count++;
    }
    return count;
}

int main()
{
    string S;
    cin >> S;
    int N = S.size();
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += countNum(N, i, S);
    }
    cout << sum << ' ';

    return 0;
}