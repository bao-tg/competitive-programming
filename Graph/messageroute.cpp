#include <bits/stdc++.h>
#define EL cout << '\n'
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define FU(x, a, b) for (int x = int(a); x <= int(b); x++)
#define PROB "rep"
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(PROB ".inp", "r")) {
        freopen(PROB ".inp", "r", stdin);
        freopen(PROB ".out", "w", stdout);
    }
}

typedef long long ll;
int n, m;
vector<vector<int>> graph;
vector<int> parent, dist;

void readinp() {
    cin >> n >> m;

    graph.resize(n + 1);
    parent.assign(n + 1, -1);
    dist.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int inp1, inp2;
        cin >> inp1 >> inp2;
        graph[inp1].pb(inp2);
        graph[inp2].pb(inp1);
    }
}

void bfs(int source) {
    queue<int> q;
    q.push(source);
    dist[source] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (dist[neighbor] == -1) { // Not visited yet
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
}

void solve() {
    bfs(1);

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> path;
    for (int at = n; at != -1; at = parent[at]) {
        path.pb(at);
    }
    reverse(all(path));

    cout << path.size() << '\n';
    for (int node : path) {
        cout << node << " ";
    }
    EL;
}

int main() {
    setIO();
    int t = 1;
    while (t--) {
        readinp();
        solve();
    }
    return 0;
}
