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

int binary(int D, vector<string> &b, int cnt, string s)
{
    if(cnt == D){
        b.push_back();
        return 0;
    }

    v.push_back(binary(D, b, cnt++, s+'0'));
    v.push_back(binary(D, b, cnt++, s+'1'));
}

int main()
{
    int D;
    ll G;
    vector<int> p;
    vector<ll> c;
    vector<string> b;

    rep(i, D){
        cin >> p[i];
        cin >> c[i];
    }

    string str;
    binary(D, b, 0, str);

    int ans=INF;
    rep(i, b.size()){
        int min = 0;
        int g = G;
        string ss = b[i];
        rep(j, ss.length()){
            g -= 100*(D-j)*p[D-j]*stoi(ss[j]);
            if(stoi(ss[j]) == 1) min += p[D-j];
        }
        rep(i, D){
            if(stoi(ss[i])==1) cycle;
            int counter=0;
            while(g > 0 && counter < p[i]){
                min++;
                g -= 100*(D-i);
                counter++;
            }
        }
        if(min <= ans) ans = min;
    }
    cout << ans;
}



