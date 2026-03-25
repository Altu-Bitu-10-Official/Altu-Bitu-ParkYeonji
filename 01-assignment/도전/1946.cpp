#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int j = 0; j < T; j++) {
        int N;
        cin >> N;

        vector<pair<int, int>> score;

        for (int i = 0; i < N; i++) {
            int m, n;
            cin >> m >> n;
            score.push_back({ m,n });
        }

        sort(score.begin(), score.end());

        int count = 1;

        for (int k = 0; k < N - 1; k++) {
            if (score[k].second < score[k + 1].second) {
                score[k + 1] = score[k];
                continue;
            }
            count++;
        }
        cout << count << '\n';
    }
    return 0;
}