#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<queue>

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
typedef std::pair<ll, ll> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;}


using namespace std;

ll N, M;
vector<ll> A, B;
vector<ll> C;

class UnionFind {
public:
    vector<ll> par;
    vector<ll> size;

    UnionFind(ll N){
        par.resize(N);
        size.resize(N);
        for(int i=0; i<N; i++){
            par[i] = i;
            size[i] = 1;
        }
    }

    ll root(ll x) {
        if (par[x] == x) return x;
        return root(par[x]);
    }

    void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(size[rx] <= size[ry]){
            par[rx] = ry;
            size[ry] += size[rx]; 
        }else{
            par[ry] = rx;
            size[rx] += size[ry]; 
        }
    }

    bool same(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return true;
        else return false;
    }

    ll get_size(ll x){
        ll rx = root(x);
        return size[rx];
    }
};

int main()
{
    cin >> N >> M;
    A.resize(M);
    B.resize(M);
    C.resize(M+1);
    rep(i, M){
        cin >> A[i] >> B[i];
    }

    UnionFind un(N);
    ll cnt = N*(N-1)/2;
    C[M] = cnt;

    for(int i=M-1; i>=0; i--){
        ll tmp1 = A[i]-1;
        ll tmp2 = B[i]-1;
        if(un.same(tmp1, tmp2)){
            C[i] = cnt;
        }else{
            cnt -= un.get_size(tmp1) * un.get_size(tmp2);
            C[i] = cnt;
            un.unite(tmp1, tmp2);
        }
    }

    reps(i, M) cout << C[i] << endl;

}