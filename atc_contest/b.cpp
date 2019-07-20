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
    string s;
    cin >> s;
    s = s+'z';
    vector<ll> v;
    ll p = 1;
    rep(i, n){
        if(s[i+1]==s[i]) p++;
        else {
            v.push_back(p);
            p = 1;
        }
    }

    if(v.size()>1){
        reps(i, v.size()-1){
            v[i] += v[i-1];
        }
    }

    ll ans;
    if(s[0]=='0'){
        ll h = v.size();
        ll m = min(2*k-1, h-1);
        ans = v[m];
        ll g = 2;
        while(m+g<h){
            if(m+g==h) ans = max(ans, v[m+g-1]-v[g-2]);
            ans = max(ans, v[m+g] - v[g-2]);
            g += 2;
        }
    }else{
        ll h = v.size();
        ll m = min(2*k, h-1);
        ans = v[m];
        ll g = 2;
        while(m+g<h){
            if(m+g==h) ans = max(ans, v[m+g-1] - v[g-1]);
            ans = max(ans, v[m+g] - v[g-1]);
            g += 2;
        }
    }
    cout << ans;
}





