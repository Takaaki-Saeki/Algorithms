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
    vector<ll> v;
    vector<ll> a(N);

    rep(i, N){
        cin >> a[i];
    }


    for(int i=0; i<N; i++){
        ll med = a[i];
        v.push_back(med);
        ll medm = -1;
        ll medp = -1;
        for(int j=0; j<N-i; j++){
            if((med!=-1)&&((j+1)%2==0)){
                if(medm==-1 || medp == -1){
                    if(med<a[i+j]){
                        medm = med;
                        med = a[i+j];
                        v.push_back(med);
                    }else{
                        medm = a[i+j];
                        v.push_back(med);
                    }
                }else{
                    if(medp<a[i+j]){
                        medm = med;
                        med = medp;
                        medp = a[i+j];
                        v.push_back(med);
                    }else if(medp>=a[i+j] && med<a[i+j]){
                        medm = med;
                        med = a[i+j];
                        v.push_back(med);
                    }else if(med>=a[i+j] && medm<a[i+j]){
                        medm = a[i+j];
                        v.push_back(med);
                    }else if(medm >= a[i+j]){
                        v.push_back(med);
                    }
                }
            }
            if((med!=-1)&&((j+1)%2!=0)){
                if(medp == -1){
                    if(a[i+j]>med){
                        medp = a[i+j];
                        v.push_back(med);
                    }
                    else if(a[i+j]<=med && a[i+j]>medm){
                        medp = med;
                        med = a[i+j];
                        v.push_back(med);
                    }
                    else if(a[i+j]<=medm){
                        medp = med;
                        med = medm;
                        medm = a[i+j];
                        v.push_back(med);
                    } 
                }
                if(medp != -1){
                    if(medp<a[i+j]){
                        v.push_back(med);
                    }else if(medp>=a[i+j] && med<a[i+j]){
                        medp = a[i+j];
                        v.push_back(med);
                    }else if(med>=a[i+j] && medm<a[i+j]){
                        medp = med;
                        med = a[i+j];
                        v.push_back(med);
                    }else if(medm >= a[i+j]){
                        medp = med;
                        med = medm;
                        medm = a[i+j];
                        v.push_back(med);
                    }

                }

            }

        }
        
    }

    ll MEDM=-1;
    ll MED=-1;
    ll MEDP=-1;
    MED = v[0];
    for(int i=0; i<v.size(); i++){
        if((i!=0)&&((i+1)%2==0)){
            if(MEDM==-1 || MEDP== -1){
                if(MED<v[i]){
                    MEDM = MED;
                    MED = v[i];
                }else{
                    MEDM = v[i];
                }
            }else{
                if(MEDP<v[i]){
                    MEDM = MED;
                    MED = MEDP;
                    MEDP = v[i];
                }else if(MEDP>=v[i] && MED<v[i]){
                    MEDM = MED;
                    MED = v[i];
                }else if(MED>=v[i] && MEDM<v[i]){
                    MEDM = v[i];
                }else if(MEDM >= v[i]){
                }
            }
        }

        if((i!=0)&&((i+1)%2!=0)){
            if(MEDP == -1){
                if(v[i]>MED){
                    MEDP = v[i];
                }
                else if(v[i]<=MED && v[i]>MEDM){
                    MEDP = MED;
                    MED = v[i];
                }
                else if(v[i]<=MEDM){
                    MEDP = MED;
                    MED = MEDM;
                    MEDM = v[i];
                } 
            }
            if(MEDP != -1){
                if(MEDP<v[i]){
                }else if(MEDP>=v[i] && MED<v[i]){
                    MEDP = v[i];
                }else if(MED>=v[i] && MEDM<v[i]){
                    MEDP = MED;
                    MED = v[i];
                }else if(MEDM >= v[i]){
                    MEDP = MED;
                    MED = MEDM;
                    MEDM = v[i];
                }
            }
            cout << MED << endl;
        }
    }
}



