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
#define INF 2e10

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef std::pair<ll, ll> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

using namespace std;
void chmin(ll &a, ll b) { if (a > b) a = b; }

int n;
vector<int> l;
int A, B, C;

ll select(int k, int a, int b, int c)
{

    if(k == n){
        if (!(a-A) || !(b-B) || !(c-C)) return INF;
        return abs(a) + abs(b) + abs(c);
    }
    ll res = select(k+1, a, b, c);
    chmin(res, select(k+1, a-l[k], b, c)+((A-a)?10 : 0));
    chmin(res, select(k+1, a, b-l[k], c)+((B-b)?10 : 0));
    chmin(res, select(k+1, a, b, c-l[k])+((C-c)?10 : 0));
    return res;
}

int main()
{
    int a, b, c;
    cin >> n >> a >> b >> c;
    A = a;
    B = b;
    C = c;
    l.resize(n);
    rep(i, n){
        cin >> l[i];
    }
    ll count = select(0, a, b, c);
    cout << count;
}