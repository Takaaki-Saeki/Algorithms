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
#define INF 2e12

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef std::pair<ll, ll> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, k) cin >> a[i];
    ll d;
    rep(i, 40){
        if(k >= pow(2, i) && k < pow(2, i+1)){
            d = i+1;
        }
    }
    vector< vector<ll> > b(n);
    rep(i, n) b[i].resize(d);

    rep(i, n){
        ll tmp = a[i];
        for(int j=d-1; j>=0; i--){
            if(tmp >= pow(2, d)){
                b[i][j] = 1;
            }else{
                b[i][j] = 0;
            }
        }
    }

    vector<ll> k2(d);
    ll tmp = k;
    for(int i=d-1; i>=0; i--){
        if(tmp >= pow(2, i)){
            k2[i] = 1;
        }else{
            k2[i] = 0;
        }
    }
    
}




