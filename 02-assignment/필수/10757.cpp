#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    string max = (a.length() > b.length()) ? a : b;
    string min = (a.length() > b.length()) ? b : a;

    string c = "";
    int quo = 0;

    int j = min.length() - 1;

    for (int i = max.length() - 1; i >= 0; i--) {
        int x = max[i] - '0';
        int y = (j >= 0) ? min[j] - '0' : 0; // 작은 배열의 원소가 존재하는지

        int sum = x + y + quo;

        c.push_back((sum % 10) + '0'); //숫자를 뒤에 추가
        quo = sum / 10;

        j--;
    }

    if (quo != 0) {
        c.push_back(quo + '0');
    }

    reverse(c.begin(), c.end()); // 마지막에 순서를 뒤바꿈

    cout << c;

    return 0;
}