#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<utility>


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

vector<ll> S, T;

bool binary_search(ll d)
{
    int l = 0;
    int h = S.size()-1;
    if(S[l]==d || S[h]==d) return true;

    int flag = 0;
    while(1){
        int m = (l + h)/2;
        if(d==S[m]) return true;
        if(d>S[m]){
            l = m;
        }
        if(d<S[m]){
            h = m;
        }
        if(h-1<=l) break;
    }
    return false;  
}

int main()
{
    int n, q;
    cin >> n;
    S.resize(n);
    rep(i, n) cin >> S[i];
    cin >> q;
    T.resize(q);
    rep(i, q) cin >> T[i];
    ll cnt = 0;
    rep(i, T.size()){
        ll d = T[i];
        if(binary_search(d)) cnt++;
    }
    cout << cnt << endl;
}



