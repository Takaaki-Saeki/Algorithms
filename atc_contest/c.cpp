#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<queue>
#include<cmath>
 
#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define reps(i,x) for(int i=1;i<=(int)(x);i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(int i=((int)(x));i>0;i--)
 
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 2e9
#define MOD 1000000007
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef std::pair<ll, ll> P;
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}

typedef std::pair<ll, ll> P;

bool pairCompare(const P& firstElof, const P& secondElof)
{
    return firstElof.second < secondElof.second;
}
 
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    ll mm = -INF;

    rep(m, k){
        vector<ll> vp;
        rep(i, k-m){
            ll mtmp = 0;
            ll left = i;
            ll right = k-m-i;
            rep(ii, left) vp.push_back(v[ii]);
            rep(jj, right) vp.push_back(v[n-1-jj]);
            sort(all(vp));
            reverse(all(vp));
            rep(ii, k-m) {
                cout << vp[ii] << endl;
                mtmp += vp[ii];
            }
            mm = max(mm, mtmp);
        }
    }

    cout << mm;
}