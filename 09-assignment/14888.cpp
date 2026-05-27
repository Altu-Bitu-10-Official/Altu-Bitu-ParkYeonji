#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> nums;
vector<int> oper(4);

long long maximum = -1000000000;
long long minimum = 1000000000;

void DFS(int step, long long cur) {
    if (step == N) {
        if (cur > maximum) {
            maximum = cur;
        }

        if (cur < minimum) {
            minimum = cur;
        }

        return;
    }

    if (oper[0] > 0) {
        oper[0]--;
        DFS(step + 1, cur + nums[step]);
        oper[0]++;
    }

    if (oper[1] > 0) {
        oper[1]--;
        DFS(step + 1, cur - nums[step]);
        oper[1]++;
    }

    if (oper[2] > 0) {
        oper[2]--;
        DFS(step + 1, cur * nums[step]);
        oper[2]++;
    }

    if (oper[3] > 0) {
        oper[3]--;
        DFS(step + 1, cur / nums[step]);
        oper[3]++;
    }
}

int main() {
    cin >> N;

    nums.resize(N); // 전역변수로 쓰던 걸 N을 입력 받은 후 크기 지정

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    DFS(1, nums[0]);

    cout << maximum << "\n";
    cout << minimum << "\n";

    return 0;
}