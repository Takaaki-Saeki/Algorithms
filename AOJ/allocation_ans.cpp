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

int n, k;
int w[100001];

bool check(int p)
{
    ll sum = 0;
    int idx = 0;

    rep(i, k){
        sum = 0;
        while(w[idx] + sum <= p){
            sum += w[idx];
            idx++;
            if(idx == n) return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> k;

    rep(i, n) cin >> w[i];

    // binary search
    ll left = 0; ll right = 100000*10000;
    while(right-left>1){
        ll mid = (left+right)/2;
        if(check(mid)) right = mid;
        else left = mid;
    }

    cout << right << endl;
}



