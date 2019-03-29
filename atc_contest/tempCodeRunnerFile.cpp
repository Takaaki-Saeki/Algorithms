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

ll N;
ll dp[105][5][5][5];
ll mod;
 
int main()
{
    mod = pow(10, 9) + 7;
    cin >> N;

    rep(i, 105){
        rep(j, 4){
            rep(k, 4){
                rep(l, 4){
                    dp[i][j][k][l] = 0;
                }
            }
        }
    }

    dp[0][3][3][3] = 1;

    reps(i, N){
        rep(j, 4){
            rep(k, 4){
                rep(l, 4){
                    dp[i][j][k][l] = (dp[i-1][k][l][0] + dp[i-1][k][l][1] + dp[i-1][k][l][2] + dp[i-1][k][l][3])%mod;
                    dp[i][1][2][l] = (dp[i-1][2][l][1] + dp[i-1][2][l][2] + dp[i-1][2][l][3])%mod;
                }
                dp[i][1][k][2] = (dp[i-1][k][2][1] + dp[i-1][k][2][2] + dp[i-1][k][2][3])%mod;
            }
        }

        dp[i][1][2][0] = 0;
        dp[i][1][0][2] = 0;
        dp[i][2][1][0] = 0;
    }

    ll ans;
    rep(i, 4){
        rep(j, 4){
            rep(k, 4){
                ans += dp[N][i][j][k];
            }
        }
    }

    cout << ans%mod << endl;
 
}