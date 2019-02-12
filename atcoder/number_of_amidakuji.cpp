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

vector<string> v;

bool genbin(int l, int cnt, string s)
{
    if(cnt == l) {
        v.push_back(s);
        return 0;
    }
    else{
        genbin(l, cnt+1, s+'0');
        if(s.back()==0) genbin(l, cnt+1, s+'1');
    }
}

int count0(int d)
{
    int cnt=0;
     for(int i=0; i<v.size(); i++){
         if(v[i][d]=='0') cnt++;
     }
     return cnt;
}

int count1(int d)
{
    int cnt=0;
    for(int i=0; i<v.size(); i++){
        if(v[i][d]=='1') cnt++;
    }
    return cnt;
}


int main()
{
    int H, W;
    vector<vector<ll>> dp;
    cin >> H >> W;
    dp.resize(H+1);
    rep(i, H){
        dp[i].resize(W+2);
    }

    // dp配列の初期化
    rep(i, H+1){
        rep(j, W+1){
            dp[i][j] = -1;
        }
        dp[i][0] = 0;
        dp[i][W+1] = 0;
    }
    

    // dpの初期値を設定
    dp[0][1] = 1;
    if(W>=2){
        for(int i=2; i<=W; i++){
            dp[0][i] = 0;
        }
    }

    ll ans;
    if(W==1){
        ans = 1;
        cout << ans;
    }else{
        genbin(W-1, 0, "");
        for(int h=0; h<H; h++){
            for(int x=1; x<=W; x++){
                if(x==1){
                    dp[h+1][x] = dp[h][x]*count0(x-1) + dp[h][x+1]*count1(x-1);
                }
                else if(x==W){
                    dp[h+1][x] = dp[h][x-1]*count1(x-2) + dp[h][x]*count0(x-2);
                }
                else{
                    dp[h+1][x] = dp[h][x-1]*count1(x-2) + dp[h][x]*count0(x-2) + dp[h][x]*count0(x-1)
                }
                
            }

        }

        




    }



    









}



