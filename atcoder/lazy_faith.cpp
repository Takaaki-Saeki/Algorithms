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
#define INF 2e10

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

using namespace std;

ll A, B, Q;
vector<ll> s;
vector<ll> t;

int main()
{
    cin >> A >> B >> Q;
    s.resize(A);
    t.resize(B);

    rep(i, A){
        cin >> s[i];
    }
    rep(i, B){
        cin >> t[i];
    }
    sort(all(s));
    sort(all(t));

    rep(i, Q){
        ll x;
        cin >> x;
        ll m = INF;
        auto itrs = lower_bound(all(s), x);
        auto itrt = lower_bound(all(t), x);
        ll is = itrs - s.begin();
        ll it = itrt - t.begin();
        ll s1, s2, t1, t2;
        if(is == s.size()){
            s1 = INF;
            s2 = s[is-1];
        }else if(is == 0){
            s1 = s[0];
            s2 = -INF;
        }else{
            s1 = s[is];
            s2 = s[is-1];
        }

        if(it == t.size()){
            t1 = INF;
            t2 = t[it-1];
        }else if(it == 0){
            t1 = t[0];
            t2 = -INF;
        }else{
            t1 = t[it];
            t2 = t[it-1];
        }
        ll a = max(t1-x, s1-x);
        ll b = max(x-s2, x-t2);
        ll c = min((s1-x)*2+(x-t2), (x-t2)*2+(s1-x));
        ll d = min((x-s2)*2+(t1-x), (t1-x)*2+(x-s2));

        m = min(m, a);
        m = min(m, b);
        m = min(m, c);
        m = min(m, d);

        cout << m << endl;
    }

}