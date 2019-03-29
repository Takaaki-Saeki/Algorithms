#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<stack>


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
    stack<ll> s;
    while(true){
        int flag = 0;
        flag++;
        if(flag >=100) break;
        char c;
        cin >> c;
        if(c!='+' && c!='-' && c!='*'){
            ll ic = c - '0';
            s.push(ic);
        }else if(c=='+' || c=='-' || c=='*'){
            ll c1 = s.top();
            s.pop();
            ll c2 = s.top();
            s.pop();
            ll c3;
            if(c == '+') c3 = c2+c1;
            else if(c=='*') c3 = c2*c1;
            else if (c=='-') c3 = c2-c1;
            cout << c3 << endl;
            s.push(c3);
        }else if(cin.eof()){
            break;
        }
    }
    ll ans = s.top();
    cout << ans << endl;
}



