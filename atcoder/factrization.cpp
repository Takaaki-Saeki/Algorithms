#include<iostream>
#include<vector>
#include<string>

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


long rec(long M,long N, vector<vector<long>> &dp)
{
    if(M==1) return 1;
    if(N==1) return 1;
    if(dp[M][N]!=-1) return dp[M][N];

    vector<long> dev;
    for(long i=1; i*i<=M; i++){
    	if(M % i == 0){
        	dev.push_back(i);
            if(i*i!=M) dev.push_back(M/i);
        }
    }
    long cnt = 0;
    rep(i, dev.size()){
    	long d = dev[i];
        dp[M/d][N-1] = rec(M/d, N-1, dp);
        cnt += dp[M/d][N-1];
    }
    return cnt;
}


int main()
{
    long N;
    long M;
    cin >> N >> M;

    vector<vector<long>> dp;
    dp.resize(M+1);
    rep(i, M+1) dp[i].resize(N+1);
    rep(i, M+1){
    	rep(j, N+1){
        	dp[i][j] = -1;
        }
    }
    long ans = rec(M, N, dp);
    cout << ans;
}
