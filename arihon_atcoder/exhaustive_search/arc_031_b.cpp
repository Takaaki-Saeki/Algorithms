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
#define INF 2e9
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef std::pair<ll, ll> P;
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}

typedef std::pair<ll, ll> P;

using namespace std;

vector< vector<ll> > a, b, c;

void dfs(ll ix, ll iy)
{
    if(c[ix-1][iy]==1 && c[ix+1][iy]==1 && c[ix][iy-1]==1 && c[ix][iy+1]==1){
        return;
    }

    if(c[ix-1][iy] == 0){
        c[ix-1][iy] = 1;
        if(ix > 1) dfs(ix-1, iy);
    }

    if(c[ix+1][iy] == 0){
        c[ix+1][iy] = 1;
        if (ix < 10) dfs(ix+1, iy);
    }

    if(c[ix][iy+1] == 0){
        c[ix][iy+1] = 1;
        if(iy < 10) dfs(ix, iy+1);
    }

    if(c[ix][iy-1] == 0){
        c[ix][iy-1] = 1;
        if(iy > 1) dfs(ix, iy-1);
    }

}

void init()
{
    rep(i, 12){
        rep(j, 12){
            c[i][j] = 0;
        }
    }
    rep(i, 12){
        c[i][0] = 1;
        c[i][11] = 1;
        c[0][i] = 1;
        c[11][i] = 1;
    }

    reps(i, 10){
        reps(j, 10){
            if(b[i][j] == 0) c[i][j] = 1;
        }
    }
}

bool is_filled()
{
    ll flag = 1;
    reps(i, 10){
        reps(j, 10){
            if(c[i][j] == 0) flag *= 0;
        }
    }

    return flag;
}

int main()
{
    b.resize(12);
    c.resize(12);
    rep(i, 12){
        b[i].resize(12);
        c[i].resize(12);
        rep(j, 12){
            b[i][j] = 0;
            c[i][j] = 0;
        }
    }

    reps(i, 10){
        string stmp;
        cin >> stmp;
        reps(j, 10){
            if(stmp[j-1] == 'o'){
                b[i][j] = 1;
            }
        }
    }

    reps(i, 10){
        reps(j, 10){
            init();
            dfs(i, j);
            if(is_filled()){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;

