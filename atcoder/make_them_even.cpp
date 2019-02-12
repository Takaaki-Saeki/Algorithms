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
typedef std::pair<ll, ll> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

using namespace std;

ll cnt = 0;
vector<ll> v;

void move(P a, P b)
{
    while(a.first != b.first || a.second != b.second){
        v.push_back(a.first);
        v.push_back(a.second); 
        if(a.first != b.first){
            a.first += (b.first-a.first)/abs(b.first-a.first);
            v.push_back(a.first);
            v.push_back(a.second);
            cnt++;
            continue;
        }
        if(a.second != b.second){
            a.second += (b.second - a.second)/abs(b.second-a.second);
            v.push_back(a.first);
            v.push_back(a.second);
            cnt++;
            continue;
        }
    }
}

void gen(vector<P> &p)
{
    ll s = p.size();
    ll s2 = s/2;
    
    for(ll i=0; i<s2; i++){
        P p1 = p[2*i];
        P p2 = p[2*i+1];
        move(p1, p2);
    }
}

void print()
{
    cout << cnt << endl;
    for(ll i=0; i<v.size()/4; i++){
        cout << v[4*i] << " " << v[4*i+1] << " ";
        cout << v[4*i+2] << " " << v[4*i+3] << endl;
    }
}

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<P> p;
    int x[501][501];
    for(ll i=0; i<H; i++){
        for(ll j=0; j<W; j++){
            ll tmp;
            cin >> tmp;
            if(tmp % 2 == 1){
                P temp;
                temp.first = i+1;
                temp.second = j+1;
                p.push_back(temp);
            }
        }
    }
    ll N;
    if(p.size() == 0 || p.size() == 1) {
        N = 0;
        cout << N;
        return 0;
    }
    gen(p);
    print();
}



