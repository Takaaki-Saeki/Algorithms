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

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, N) cin >> v[i];

    if(N==1){
        cout << v[0] << endl;
        return 0;
    }

    rep(i, N){
        if(i!=N-1) cout << v[i] << " ";
        if(i==N-1) cout << v[i] << endl;
    }

    for(int i=1; i<N; i++){
        int c = v[i];
        int j=i-1;
        while(j>=0 && v[j]>c){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = c;

        rep(i, N){
            if(i!=N-1) cout << v[i] << " ";
            if(i==N-1) cout << v[i] << endl;
        }
    }
}



