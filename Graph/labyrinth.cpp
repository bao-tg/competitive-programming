#include <bits/stdc++.h>
#define EL cout<<'\n'
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pil pair<int,ll>
#define can(n, q) round(exp(log(n) / q))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(v) (v).begin(),(v).end()
#define FU(x,a,b) for(int x=int(a);x<=int(b);x++)
#define FD(x,a,b) for(int x=int(a);x>=int(b);x--)
#define PROB "rep"
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp", "r",stdin);
        freopen(PROB".out", "w",stdout);
    }
}

typedef long long ll;
typedef double db;
int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<pair<int,int>>> parents;
bool flag = false;
string path = "";
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
char direction[] = {'D', 'U', 'L', 'R'};
int start_x, start_y, end_x, end_y;

void readinp(){
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));
    parents.assign(n, vector<pair<int,int>>(m, {-1, -1}));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];

            if (grid[i][j] == 'A'){
                start_x = i;
                start_y = j;
            }

            if (grid[i][j] == 'B'){
                end_x = i;
                end_y = j;
            }
        }
    }
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();

        if (grid[node.first][node.second] == 'B'){
            flag = true;
            return;
        }

        for (int i = 0; i < 4; i++){
            int new_x = node.first + dx[i];
            int new_y = node.second + dy[i];

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !visited[new_x][new_y] && grid[new_x][new_y] != '#'){
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
                parents[new_x][new_y] = {node.first, node.second};
            }
        }
    }
}

void path_reconstruct(){
    if (!flag){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    pair<int, int> cur = {end_x, end_y};

    while (cur != make_pair(start_x, start_y)){
        int cur_x = cur.first;
        int cur_y = cur.second;

        int prev_x = parents[cur_x][cur_y].first;
        int prev_y = parents[cur_x][cur_y].second;

        pair<int, int> prev = parents[cur_x][cur_y];

        for (int i = 0; i < 4; i++){
            int prev_x_tmp = cur_x + dx[i];
            int prev_y_tmp = cur_y + dy[i];

            if (prev_x_tmp == prev_x && prev_y_tmp == prev_y){
                path += direction[i];
                break;
            }
        }
        cur = prev;
    }

    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    cout << path << '\n';
}
void solve() {
    bfs(start_x, start_y);
    path_reconstruct();
}
int main(){
    setIO();
    int t = 1;
//  cin >> t;
    while (t--){
        readinp();
        solve();
    }
    return 0;
}

