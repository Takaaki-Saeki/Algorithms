#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<queue>

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
int gcd(int a,int b){return b?gcd(b,a%b):a;}


using namespace std;

int main()
{
    ll n, q;
    string s;
    cin >> n >> q >> s;
    string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ll v[26];
    ll mi[26];
    ll ma[26];
    ll ex[26];
    rep(i, 26){
        v[i] = 0;
        ex[i] = 0;
        mi[i] = INF;
        ma[i] = -INF;
    }

    rep(i, q){
        char t, d;
        cin >> t >> d;
        rep(j, al.size()){
            if(al[j]==t){
                cout << d << endl;
                if(d == 'L') v[j]--;
                if(d == 'R') v[j]++;
                mi[j] = min(v[j], mi[j]);
                ma[j] = max(v[j], ma[j]);
                ex[j] = 1;
            }
        }
    }

    ll cnt = 0;
    rep(i, n){
        char s0 = s[i];
        ll p;
        rep(j, al.size()){
            if(al[j] == s0) p = j;
        }
        if(ex[p] == 1){
            cout << mi[p] << ma[p] << endl;
            cout << i << endl;
            ll tmp0 = i + mi[p];
            ll tmp1 = i + ma[p];
            cout << tmp0 << tmp1 <<
            if(tmp0 >= 0 && tmp1 <= n-1) cnt++;
        }
    }
    cout << cnt;
}