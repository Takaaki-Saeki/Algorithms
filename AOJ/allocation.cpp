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
vector<int> v;

bool check(int P)
{
    int cnt = 1;
    int pn = P;
    int flag = 0;
    for(int i=0; i<v.size(); i++){
        flag++;
        if(pn>=v[i]){
            pn -= v[i];
        }else if(P>=v[i]){
            cnt++;
            pn = P;
            i--;
        }else{
            return 0;
        }
        if(cnt>=v.size()) break;
    }
    if(cnt<=k) return 1;
    else return 0;
}

int binary_search(int sum)
{
    int ans = -1;
    int l = 0;
    int h = sum-1;
    if(check(l+1)) return 1;
    if(check(h+1)&&!check(h)) return h+1; 
    int flag = 0;
    while(1){
        int m = (l+h)/2;
        if(m!=0&&check(m+1)&&!check(m)){
            ans = m+1;
            break;
        }
        if(check(m+1)){
            h = m;
        }else{
            l = m;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    v.resize(n);
    ll sum=0;
    rep(i, n){
        cin >> v[i];
        sum += v[i];
    }
    int ans = binary_search(10);
    cout << ans << endl;
}



