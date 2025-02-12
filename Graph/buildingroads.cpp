#include <bits/stdc++.h>
#define EL cout << '\n'
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define FU(x, a, b) for (int x = int(a); x <= int(b); x++)
#define FD(x, a, b) for (int x = int(a); x >= int(b); x--)
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
typedef vector<int> vi;
int n, m;
vector<bool> visited;
vector<vi> graph;
vi ans;
int cnt = 0;

void readinp() {
    cin >> n >> m;

    // Resize graph to fit n nodes (0-based index)
    graph.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int inp1, inp2;
        cin >> inp1 >> inp2;

        graph[inp1].push_back(inp2);
        graph[inp2].push_back(inp1);
    }
}

void dfs(int source) {
    if (visited[source]) return;

    visited[source] = true;
    for (auto v : graph[source]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            ans.pb(i);
            dfs(i);
        }
    }

    cout << cnt-1; EL; // Print number of connected components

    for (auto it = ans.begin(); it != ans.end()-1; it++){
        cout << *it << " " << *(it+1) << "\n";
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
