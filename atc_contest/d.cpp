#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<cmath>
#include<queue>

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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

using namespace std;

int main()
{
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(all(a));
    reverse(all(a));
    sort(all(b));
    reverse(all(b));
    sort(all(c));
    reverse(all(c));

    vector<ll> p, q, r;

    int l0 = 0;
    int l1 = 0;
    int l2 = 0;
    p.push_back(a[l0]);
    q.push_back(b[l1]);
    r.push_back(c[l2]);
    ll cnt = 0;
    while(1){
        cnt++;
        ll g;
        ll m = -INF;
        if(l0+1<x && a[l0+1]>m){
            g = 0;
            m = a[l0+1];
        }
        if(l1+1<y && b[l1+1]>m){
            g = 1;
            m = b[l1+1];
        }
        if(l2+1<z && c[l2+1]>m){
            g=2;
            m = c[l2+1];
        }

        if(g==0){
            l0++;
            p.push_back(a[l0]);
        }else if(g==1){
            l1++;
            q.push_back(b[l1]);
        }else if(g==2){
            l2++;
            r.push_back(c[l2]);
        }
        if(cnt == 3000) break;
        if(l0==x-1 && l1==y-1 && l2==z-1) break;
    }

    rep(i, x) cout << p[i] << endl;

    priority_queue<ll> pq;
    rep(i, p.size()){
        rep(j, q.size()){
            rep(n, r.size()){
                pq.push(p[i]+q[j]+r[n]);
            }
        }
    }

    rep(i, k){
        cout << pq.top() << endl;
        pq.pop();
    }
}
