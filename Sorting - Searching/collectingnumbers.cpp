#include <bits/stdc++.h>
#define EL cout << '\n'
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
#define FU(x,a,b) for (int x = int(a); x <= int(b); x++)
#define FD(x,a,b) for (int x = int(a); x >= int(b); x--)
#define PROB "bao"
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(PROB".inp", "r")) {
        freopen(PROB".inp", "r", stdin);
        freopen(PROB".out", "w", stdout);
    }
}

typedef long long ll;
typedef double db;

ll n;
vector<pii> x;

void readinp() {
    cin >> n;
    x.resize(n);
    FU(i, 1, n) {
        cin >> x[i-1].first;
        x[i-1].second = (i-1);
    }
}

// Key idea -> keep track the position, don't think manually, think computationally!!!.

void solve() {
    sort(x.begin(), x.end());

    int ans = 1;

    FU(i, 1, n-1){
        if (x[i].second < x[i-1].second){
            ans += 1;
        }
    }

    cout << ans;
}

int main() {
    setIO();
    int t = 1;
    // cin >> t;
    while (t--) {
        readinp();
        solve();
    }
    return 0;
}
