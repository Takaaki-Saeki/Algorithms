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

int count(int N, int p, int f)
{
    if(N<=0) return 1;

    if(p == N-1){
        return 1;
    }

    if(f == 0){
        return count(N, p+1, 0) + count(N, p+1, 1);
    }else{
        return count(N, p+1, 0);
    }
}

int main()
{
    ll h, w, k;
    cin >> h >> w >> k;

    ll dp[105][10];
    rep(i, 105){
        rep(j, 10){
            dp[i][j] = 0;
        }
    }
    // 横軸の数字が0originであることに注意
    dp[0][0] = 1;
    if(w == 1){
        if(k == 1) cout << 1;
        else cout << 0;
    }else{
        rep(i, h){
            rep(j, w){
                if(j == 0){
                    dp[i+1][j] = dp[i][j]*count(w-2, 0, 0) + dp[i][j+1]*count(w-3, 0, 0);
                }else if(j == w-1){
                    dp[i+1][j] = dp[i][j]*count(w-2, 0, 0) + dp[i][j-1]*count(w-3, 0, 0);
                }else{
                    dp[i+1][j] = dp[i][j-1]*count(j-2, 0, 0)*count(w-j-2, 0, 0) + dp[i][j+1]*count(j-1, 0, 0)*count(w-j-3, 0, 0);
                    dp[i+1][j] += dp[i][j]*count(j-1, 0, 0)*count(w-j-2, 0, 0);
                }
            }
        }
        cout << dp[h][k-1];
    }

}
