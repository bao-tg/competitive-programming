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
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


void readinp(){
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
}

void dfs(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#' || visited[x][y])
        return;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        dfs(new_x, new_y);
    }
}

void solve(){
    int room_count = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == '.' && !visited[i][j]){
                dfs(i, j);
                room_count++;
            }
        }
    }

    cout << room_count;
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
