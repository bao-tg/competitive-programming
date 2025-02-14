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
int const max_N = 1e9;
int n;

void readinp(){
    cin >> n;
}

void solve(){
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;  // Base case: 0 requires 0 steps.

    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        for (char c : s) {
            int digit = c - '0';
            if (digit > 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }

    cout << dp[n];
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
