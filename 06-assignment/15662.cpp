#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T; //톱니의 개수
    cin >> T;

    vector<string> gear(T);
    for (int i = 0; i < T; i++) {
        cin >> gear[i]; //톱니의 상태?
    }

    vector<int> top(T, 0); //12시 방향 자성

    int K; //회전 횟수
    cin >> K;

    while (K--) {
        int x, d; //x : 톱니 번호, d : 회전방향
        cin >> x >> d;
        x--;

        vector<int> dir(T, 0); //direction : x번째 톱니의 회전방향
        dir[x] = d;

        for (int i = x; i < T - 1; i++) { //x번째 톱니의 오른쪽에 있는 톱니들
            int right = (top[i] + 2) % 8;
            int nextLeft = (top[i + 1] + 6) % 8;

            if (gear[i][right] != gear[i + 1][nextLeft]) { //x번째 톱니의 3번째 값과 x+1번째 톱니의 6번째 값을 비교
                dir[i + 1] = -dir[i]; //자성이 다르면 반대방향으로 회전
            }
            else {
                break;
            }
        }

        for (int i = x; i > 0; i--) { //x의 왼쪽
            int left = (top[i] + 6) % 8;
            int preRight = (top[i - 1] + 2) % 8;

            if (gear[i][left] != gear[i - 1][preRight]) {
                dir[i - 1] = -dir[i];
            }
            else {
                break;
            }
        }

        for (int i = 0; i < T; i++) { //회전
            if (dir[i] == 1) { //시계방향은 12시 방향 왼쪽 인덱스로
                top[i] = (top[i] + 7) % 8;
            }
            else if (dir[i] == -1) { //반시계는 오른쪽 인덱스로
                top[i] = (top[i] + 1) % 8;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < T; i++) {
        if (gear[i][top[i]] == '1') {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}