#include<iostream>
#include<vector>

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
    vector<int> p;

    p.push_back(2);
    for(int n=3; n<=50; n++){
        int cnt = 0;
        for(int i=0; i<p.size(); i++){
            if(n % p[i] != 0) cnt++;
        }
        if(cnt == p.size()) p.push_back(n);
    }

    long ans = 0;
    /*74回割り切れるものを数える*/
    reps(n, N){
        rep(i, p.size()){
            int cnt = 0;
            while(n % p[i] == 0){
                n /= p[i];
                cnt++;
            }
            if(cnt >= 74) ans++;
        }
    }
    /*24, 2回割り切れるものを数える*/
    reps(n, N){
        int c24 = 0;
        int c2 = 0;
        rep(i, p.size()){
            int cnt_24 = 0;
            int cnt_2 = 0;
            int nb = n;
            while(n % p[i] == 0){
                n /= p[i];
                cnt_24++;
            }
            while(nb % p[i] == 0){
                nb /= p[i];
                cnt_2++;
            }
            if(cnt_24>=24) c24++;
            if(cnt_2>=2) c2++;
        }
        ans += c24*(c2-1);
    }

    /*14, 4回割り切れるものを数える*/
    reps(n, N){
        int c14 = 0;
        int c4 = 0;
        rep(i, p.size()){
            int cnt_14 = 0;
            int cnt_4 = 0;
            int nb = n;
            while(n % p[i] == 0){
                n /= p[i];
                cnt_14++;
            }
            while(nb % p[i] == 0){
                nb /= p[i];
                cnt_4++;
            }
            if(cnt_14>=14) c14++;
            if(cnt_4 >= 4) c4++;
        }
        ans += c14*(c4-1);
    }

    /*4,4,2回割り切れるものを数える*/
    reps(n, N){
        int c4 = 0;
        int c2 = 0;
        rep(i, p.size()){
            int cnt_4 = 0;
            int cnt_2 = 0;
            int nb = n;
            while(n % p[i]==0){
                n /= p[i];
                cnt_4++;
            }
            while(nb % p[i]==0){
                nb /= p[i];
                cnt_2++;
            }
            if(cnt_4 >= 4) c4++;
            if(cnt_2 >= 2) c2++;
        }
        ans += max(c4*(c4-1)*(c2-2), 0);
    }

    cout << ans;
}



