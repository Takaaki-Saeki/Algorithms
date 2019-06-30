#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<queue>

#define rep(i,x) for(ll i=0;i<(int)(x);i++)
#define reps(i,x) for(ll i=1;i<=(int)(x);i++)
#define rrep(i,x) for(ll i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(ll i=((int)(x));i>0;i--)

#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 2e9

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef std::pair<ll, ll> P;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

using namespace std;

ll n, m;
vector< vector<ll> > v;

void dfs(ll node, vector< vector<ll> > &vs, vector<ll> &color)
{
    rep(i, n){
        if(vs[node][i] == 1 && color[i] == 0){
            color[i] = 1;
            dfs(i, vs, color);
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<P> pv(m);
    v.resize(n);
    rep(i, n){
        v[i].resize(n);
        rep(j, n){
            v[i][j] = 0;
        }
    }

    rep(i, m){
        ll tmp0, tmp1;
        cin >> tmp0 >> tmp1;
        pv[i].first = tmp0-1;
        pv[i].second = tmp1-1;
        v[tmp0-1][tmp1-1] = 1;
        v[tmp1-1][tmp0-1] = 1;
    }

    ll ans = 0;

    rep(i, m){
        vector< vector<ll> > vs = v;
        ll t0, t1;
        t0 = pv[i].first;
        t1 = pv[i].second;
        vs[t0][t1] = 0;
        vs[t1][t0] = 0;
        vector<ll> color(n, 0);
        dfs(0, vs, color);
        rep(i, n){
            if(color[i] == 0){
                ans++;
                break;
            }
        }
    }

    cout << ans;



}
