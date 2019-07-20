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
 
using namespace std;

int main(){
    ll n, m;
    cin >> n >> m;
    ll ans;
    if(n == 1){
        if(m==1) ans = 1;
        else if(m>2) ans = m-2;
        else ans = 0;
    }else if(m == 1){
        if(n==1) ans = 1;
        else if(n>2) ans = n-2;
        else ans = 0;
    }else{
        ans = (n-2)*(m-2);
    }
    cout << ans;
}