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
#define PROB "bao"
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
ll n;
vector<ll> p;


void readinp(){
    cin >> n;

    p.resize(n);

    FU(i, 1, n){
        cin >> p[i-1];
    }
}

int abs(int a){
    if (a >= 0){
        return a;
    }
    else{
        return -a;
    }
}

void solve(){
    sort(p.begin(), p.end());

    ll ans = 0;

    if (n % 2 == 0){
        ll central_lower = p[n/2 - 1];
        ll central_larger = p[n/2];
        ll tmp = 0;
        FU(i, 1, n){
            tmp += abs(central_lower - p[i-1]);
            ans += abs(central_larger - p[i-1]);
        }
        ans = max(tmp, ans);
    }
    else{
        ll central = p[n/2];
        FU(i, 1, n){
            ans += abs(central - p[i-1]);
        }
    }

    cout << ans;
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
