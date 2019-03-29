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

bool prime(int n)
{
    int cnt=0;
    for(int i=1; i*i<=n; i++){
        if(i!=1 && n%i==0) cnt++;
    }
    if(cnt==0) return 1;
    else return 0;
}

int main()
{
    int N;
    cin >> N;
    vector<ll> v(N);
    rep(i, N){
        cin >> v[i];
    }
    ll ans=0;

    rep(i, N){
        int n = v[i];
        ans += prime(n);
    } 
    cout << ans << endl;
}



