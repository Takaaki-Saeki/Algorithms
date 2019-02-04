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

bool pairCompare(const P& firstElof, const P& secondElof)
{
        return firstElof.second > secondElof.second;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<long>> v(N+1);
    vector<pair<int, long>> p;

    rep(i, N){
        int t;
        long d;
        cin >> t >> d;
        v[t].push_back(d);
    }
    reps(i, N){
        if(!v[i].empty()) sort(all(v[i]), std::greater<long>());
    }

    reps(i, N){
        rep(j, v[i].size()){
            pair<int, long> tp;
            tp.first = i;
            tp.second = v[i][j];
            p.push_back(tp);
        }
    }
    sort(all(p), pairCompare);
    long ans = 0;
    vector<int> r(N+1, 0);
    rep(i, i<K){
        r(p[i].first)++;
        ans += p[i].second;
    }
    int x=0;
    reps(i, N){
        if(r[i]>0) x++;
    }
    ans += x*x;

    long mx=ans;
    for(int i=K-1; i>=0; i--){
        int y = p[i].first;
        if(r[y]>=2){
            for(j=K; j<=N; j++){
                if(r[p[j].first]==0){
                    ans -=p[i].second;
                    ans +=p[j].second;
                    ans -= x*x;
                    x++;
                    r[p[j].first]++;
                    ans += x*x;
                }
            }
        }
        if(ans>=mx) mx = ans;
    }
    cout << mx;
}



