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
    ll k;
    ll x, y;
    vector<P> v;
    cin >> k >> x >> y;

    if(k%2 != (x+y)%2){
        cout << -1;
        return 0;
    }

    ll p = x + y;
    ll q = x - y;

    ll dx = 0;
    ll dy = 0;

    ll cnt = 0;

    while(abs(p) > 2*k || abs(q) > 2*k){
        ll gx = 0;
        ll gy = 0;
        if(abs(p) > 2*k){
            if(p > 0){
                p -= k;
                gx = k;
            }else{
                p += k;
                gx = -k;
            }
        }
        if(abs(q) > 2*k){
            if(q > 0){
                q -= k;
                gy = k;
            }else{
                q += k;
                gy = -k;
            }
            ll rx = (gx + gy)/2;
            ll ry = (gx - gy)/2;
            dx += rx;
            dy += ry;
            P pp;
            pp.first = dx;
            pp.second = dy;
            v.push_back(pp);
        }
        cnt++;
    }
    if(p%2 == 0){
        ll gx = 0;
        ll gy = 0;
        if(p < dx+dy){
            gx = -k;
        }else{
            gx = k;
        }

        if(q < dx-dy){
            gy = -k;
        }else{
            gy = k;
        }
        ll rx = (gx + gy)/2;
        ll ry = (gx - gy)/2;
        dx += rx;
        dy += ry;
        P pp;
        pp.first = dx;
        pp.second = dy;
        v.push_back(pp);
        P pp1;
        pp1.first = x;
        pp1.second = y;
    }else{
        
    }
}