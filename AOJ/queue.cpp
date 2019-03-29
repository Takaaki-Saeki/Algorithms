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
int gcd(int a,int b){return b?gcd(b,a%b):a;}

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector< pair<string, int> > p(n);
    queue< pair<string, int> > qu;
    rep(i, n){
        pair<string, int> p;
        cin >> p.first;
        cin >> p.second;
        qu.push(p);
    }
    int time=0;
    int flag = 0;
    while(!qu.empty()){
        pair<string, int> pt = qu.front();
        qu.pop();
        if(pt.second <= q){
            time += pt.second;
            cout << pt.first << " " << time << endl;
        }else{
            pt.second -= q;
            time += q;
            qu.push(pt);
        }
    }
}



