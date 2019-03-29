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


int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> v(N);
    string s;
    cin >> s;
    int n=0;
    rep(i, N){
        if((i != 0) && (s[i-1] == 'A') && (s[i] == 'C')){
            n++;
        }
        v[i] = n;
    }

    rep(i, Q){
        int l, r;
        cin >> r >> l;
        cout << v[l-1] - v[r-1] << endl;
    }
}



