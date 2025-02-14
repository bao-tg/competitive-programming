#include <bits/stdc++.h>
#define EL cout << '\n'
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int n, m;
vector<vector<int>> graph;
vector<int> ans;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void readinp() {
    cin >> n >> m;
    graph.assign(n + 1, vector<int>());
    ans.assign(n + 1, 0);  // 0 means unvisited

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

bool bfs(int source) {
    queue<int> q;
    q.push(source);
    ans[source] = 1;  // Start coloring with 1

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (ans[neighbor] == 0) {  // Not visited
                ans[neighbor] = 3 - ans[node];  // Toggle color (1 ↔ 2)
                q.push(neighbor);
            } else if (ans[neighbor] == ans[node]) {
                return false;  // Conflict found, graph is not bipartite
            }
        }
    }
    return true;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0) {  // Not visited
            if (!bfs(i)) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main() {
    setIO();
    readinp();
    solve();
    return 0;
}
