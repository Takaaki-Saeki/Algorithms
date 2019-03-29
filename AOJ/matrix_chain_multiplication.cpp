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

const int n = 100;

int main()
{
    int dp[n+1][n+1];
    int p[n+1];

    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        ll tmp;
        cin >> p[i];
        cin >> tmp;
    }
    cin >> p[N-1];
    cin >> p[N];

    rep(i, n+1){
        rep(j, n+1){
            dp[i][j] = INF;
        }
    }
    reps(i, n){
        dp[i][i] = 0;
    }

    for(int l=1; l<N; l++){
        for(int i=1; i+l<=N; i++){
            int m = INF;
            for(int j=i; j<i+l; j++){
                m = min(m, dp[i][j] + dp[j+1][i+l] + p[i-1]*p[j]*p[i+l]);
            }
        } 
    }
    cout << dp[1][N] << endl;
}



