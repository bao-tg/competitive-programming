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
int const N = 1e6+5;
int const M = 1e9+7;
int n, x;
int coins[N];


void readinp(){
    cin >> n >> x;

    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }
}

void solve(){
    int dp[x+1];

    memset(dp, 0, sizeof(dp));  // Initialize all dp elements to 0
    dp[0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = coins[i]; j <= x; j++){
            dp[j] += dp[j-coins[i]];
            dp[j] %= M;
        }
    }

    cout << dp[x];
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

