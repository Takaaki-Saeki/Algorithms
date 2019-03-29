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

void merge(vector<int> v, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1+1);
    vector<int> R(n2+1);
    rep(i, n1){
        L[i] = v[left+i];
    }
    rep(i, n2){
        R[i] = v[mid+i];
    }
    L[n1] = INF;
    R[n2] = INF;
    int i=0; 
    int j=0;
    for(int k=left; k<=right-1; k++){
        if(L[i]<=R[i]){
            v[k] = L[i];
            i++;
        }else{
            v[k] = R[j];
            j++;
        }
    }
}

void merge_sort(vector<int> v, int left, int right)
{
    if(left+1 < right){
        int mid = (left+right)/2;
        merge_sort(v, left, mid);
        merge_sort(v, mid, right);
        merge(v, left, mid, right);
    }
}



int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    merge_sort(v, 0, n-1);

    rep(i, n) cout << v[i];
}



