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

long dfs(int N, long X, vector<ll> &a)
{
    if(N==0) return 1;

    if(N!=0 && X==1) return 0;

    if(X>1 && X<=a[N-1]+1) return dfs(N-1, X-1, a);

    if(X==a[N-1]+2) return dfs(N-1, a[N-1], a) + 1;

    if(X>=a[N-1]+3 && X<2*a[N-1]+3){
        return dfs(N-1, a[N-1], a)+dfs(N-1, X-a[N-1]-2, a)+1;
    }
    if(X == 2*a[N-1]+3){
        return 2*dfs(N-1, a[N-1], a)+1;
    }
}

int main()
{
    int N;
    long X;
    cin >> N >> X;
    vector<ll> a(N+1);
    a[0] = 1;
    for(int i=0; i<N; i++){
        a[i+1] = 2*a[i] + 3;
    }
    long ans = dfs(N, X, a);
    cout << ans;
}
