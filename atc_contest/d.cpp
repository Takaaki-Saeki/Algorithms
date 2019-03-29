#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<cmath>

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

ll N, K;
vector<ll> a;
vector<string> s;

string binary(ll d, int mnum)
{
    ll db = d;
    int p = mnum;
    string s = "";
    while(d > 0 || p >= 0){
        if(d >= pow(2, p)){
            d -= pow(2, p);
            s += '1';
        }else{
            s += '0';
        }
        p--;
    }
    return s;
}

int count0(ll d)
{
    int cnt = 0;
    rep(i, N){
        if(s[i][d]=='0') cnt++; 
    }
    return cnt;
}

ll xxor(string str)
{
    ll sum = 0;
    rep(i, N){
        rep(j, s[i].size()){
            if(s[i][j]!=str[j]){
                sum += pow(2, s[i].size()-1-j);
            }
        }
    }
    return sum;
}



int main()
{
    cin >> N >> K;
    a.resize(N);
    s.resize(N);
    rep(i, N){
        ll tmp;
        string stmp;
        cin >> tmp;
        a[i] = tmp;
        stmp = binary(tmp, 40);
        s[i] = stmp;
    }
    string ks = binary(K, 40);

    ll m = -INF;
    rep(i, ks.size()){
        string st = "";
        if(ks[i]=='1'){
            if(i == 0){
                st += '0';
                for(int j=1; j<ks.size(); j++){
                    if(2*count0(j)>N) st += '1';
                    else st += '0'; 
                }
            }else if(i == N-1){
                for(int j=0; j<N-1; j++){
                st += ks[j];
                }
                st += '0';
            }else{
                for(int j=0; j<i; j++){
                st += ks[j];
                }
                st += '0';
                for(int j=i+1; j<ks.size(); j++){
                    if(2*count0(j)>N) st += '1';
                    else st += '0'; 
                }
            }
            m = max(m, xxor(st));
        }
    }
    if(m == -INF){
        string z = "";
        rep(i, ks.size()) z += '0';
        m = xxor(z);
    }
    cout << m;
    return 0;
}



