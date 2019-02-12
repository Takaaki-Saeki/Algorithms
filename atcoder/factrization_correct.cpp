#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<unordered_map>


#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define reps(i,x) for(int i=1;i<=(int)(x);i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(int i=((int)(x));i>0;i--)

#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 2e9

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0;}
typedef long long ll;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

using namespace std;

long combination(long b, int N)
{
    long sib = 1;
    long par = 1;
    rep(i, b){
        sib *= (b+N-1-i);
        par *= (b-i);
    }
    return sib/par;
}

long factoring(long M, int N)
{
    vector<long> p;
    p.push_back(2);
    for(long n=2; n<=M; n++){
        int cnt = 1;
        for(int j=0; j<p.size(); j++){
            if(n % p[j] == 0) cnt *= 0;
        }
        if(cnt == 1) p.push_back(n);
    }

    unordered_map<long, int> u;
    long ans = 1;
    for(int i=0; i<p.size(); i++){
        long Mb = M;
        long pi = p[i];
        long counter = 0;
        while(Mb % pi == 0){
            Mb /= pi;
            counter++;
        }
        u[pi] = counter;
    }
    for(int i=0; i<p.size(); i++){
    	int b = u[p[i]] ;
        cout << combination(b, N) << endl;
        ans *= combination(b, N);
    }
    long mod = 1000000007;
    ans = ans%mod;
    return ans;

}


int main()
{
    long M;
    int N;
    cin >> N >> M;
    cout << factoring(M, N);
}

