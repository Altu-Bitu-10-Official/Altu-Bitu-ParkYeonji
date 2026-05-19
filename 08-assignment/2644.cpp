#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph(101);
vector<int> visited(101, false);

int bfs(int x, int y) {
    queue<int> q;
    q.push(x);
    vector<int> dist(101, 0);

    visited[x] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == y) {
            return dist[y];
        }

        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = 1;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    int G;
    cin >> G;

    int x, y;
    cin >> x >> y;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int dist = bfs(x, y);

    cout << dist;
    return 0;
}