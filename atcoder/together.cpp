#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<cmath>


#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define reps(i,x) for(int i=1;i<=(int)(x);i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(int i=((int)(x));i>0;i--)

#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 2e9

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n), vm(n), vp(n), vc(3*n);

    rep(i, n){
        cin >> v[i];
        vm[i] = v[i] - 1;
        vp[i] = v[i] + 1;
    }
    rep(i, n){
        vc[i] = v[i];
        vc[n+i] = vm[i];
        vc[2*n+i] = vp[i];
    }

    sort(all(vc));
    vc.push_back(INF);

    ll cnt = 1;
    ll ans = -INF;
    rep(i, 3*n){
        if(vc[i] == vc[i+1]){
            cnt++;
        }else{
            ans = max(ans, cnt);
            cnt=1;
        }
    }

    cout << ans;
}
