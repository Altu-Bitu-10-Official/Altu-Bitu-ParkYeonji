#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int G;
    cin >> G;

    int N;
    cin >> N;

    vector<vector<int>> graph(G + 1);
    vector<bool> visited(G + 1, false);
    stack<int> st;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    st.push(1);

    while (!st.empty()) {
        int cur = st.top();
        st.pop();

        if (visited[cur]) continue;

        visited[cur] = true;

        for (int next : graph[cur]) {
            if (!visited[next]) {
                st.push(next);
            }
        }
    }

    int count = 0;

    for (int i = 2; i <= G; i++) {
        if (visited[i]) count++;
    }

    cout << count;

    return 0;
}