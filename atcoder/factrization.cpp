#include<bits/stdc++.h>

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

ll rec(ll M,int N, ll &dp, ll &dev, ll cnt)
{
    if(M==1) return 1;
    if(N==1) return 1;
    if(dp[M][N]!=-1) return dp[M][N];

    rep(i, dev.size()){
        ll d = dev[i];
        dp[M/d][N-1] = rec(M/d, N-1, dp, dev);
        cnt += dp[M/d][N-1];
    }
    return cnt;
}


int main()
{
    int N;
    ll M;
    cin >> N >> M;
    vector<vector<ll>> dp;
    dp.resize(M);
    rep(i, M) dp[i].resize(N);

    ll cnt=0;
    vector<ll> dev;
    for(int i=0; i*i<=M; i++){
        if(M!=i){
            dev.push_back(i);
            if(i*i!=M) dev.push_back(M/i);
        }
    }
    ll ans = rec(M, N, dp, dev, 0);
    cout << ans;
}



