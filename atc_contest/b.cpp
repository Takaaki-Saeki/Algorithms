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
#define INF 2e12

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef std::pair<ll, ll> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<P> vp;

    s += 'e';

    ll cr = 0;
    ll cl = 0;
    rep(i, s.size()-1){
        P tmp;
        if(s[i] == 'R'){
            cr++;
        }
        if(s[i] == 'L'){
            cl++;
            if(s[i+1] != 'L'){
                tmp.first = cr;
                tmp.second = cl;
                vp.push_back(tmp);
                cr = 0;
                cl = 0;
            }
        }
    }

    string ans = "";
    rep(i, vp.size()){
        if((vp[i].first+vp[i].second)%2 == 0){
            ll aa = (vp[i].first+vp[i].second)/2;
            rep(j, vp[i].first-1){
                ans += "0 ";
            }
            ans += to_string(aa);
            ans += ' ';
            ans += to_string(aa);
            ans += ' ';
            rep(j, vp[i].second-1){
                ans += "0 ";
            }
        }else{
            ll mm = min(vp[i].first, vp[i].second);
            if(mm % 2 == 0){
                rep(j, vp[i].first-1){
                    ans += "0 ";
                }
                ans += to_string(vp[i].first);
                ans += ' ';
                ans += to_string(vp[i].second);
                ans += ' ';
                rep(j, vp[i].second-1){
                    ans += "0 ";
                }
            }else{
                rep(j, vp[i].first-1){
                    ans += "0 ";
                }
                ans += to_string(vp[i].second);
                ans += ' ';
                ans += to_string(vp[i].first);
                ans += ' ';
                rep(j, vp[i].second-1){
                    ans += "0 ";
                }
            }
        }
    }
    string tt = "";
    rep(i, ans.size()-1){
        tt += ans[i];
    }

    cout << tt;


}

