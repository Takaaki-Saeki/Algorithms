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

int main()
{
    int N;
    long M;
    cin >> N >> M;
    vector<long> v;

    for(int i=1; i*i<=M; i++){
        if(n % i ==0) {
            v.push_back(i);
            if(i!=1 && i*i!=M) v.push_back(M/i);
        }
    }
    sort(all(v));
    auto itr = lower_bound(all(v), N);
    int index = itr - v.begin();
    long dev = v[index];
    long ans = M/dev;

    cout << ans;
}



