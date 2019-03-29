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

class Node{
public:
    ll val;
    Node *next;
    Node *prev;
};

Node *nil;
void init()
{
    nil = new Node;
    nil->val = -1;
    nil->next = nil;
    nil->prev = nil;
}

void insert(ll d)
{
    Node *in;
    in = new Node;
    in->val = d;
    in->next = nil->next;
    in->next->prev = in;
    nil->next = in;
    in->prev = nil;
}

void del(ll d)
{
    Node *tmp = nil;
    int flag=0;
    while(1){
        flag++;
        if(flag >= 100) break;
        if(tmp->val==d){
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            break;
        }else if(tmp->next==nil) {
            break;
        }
        tmp = tmp->next;
    }
}

void delF()
{
    nil->next = nil->next->next;
    nil->next->prev = nil;
}

void delL()
{
    nil->prev = nil->prev->prev;
    nil->prev->next = nil;
}

void print()
{
    Node *tmp = nil->next;
    while(1){
        if(tmp == nil) break;
        else{
            if(tmp==nil->next) cout << tmp->val;
            else cout << " " << tmp->val;
            tmp = tmp->next;
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    rep(i, n){
        string s;
        ll d;
        cin >> s >> d;
        init();
        if(s=="insert") insert(d);
        if(s=="delete") del(d);
        if(s=="deleteFirst") delF();
        if(s=="deleteLast") delL();
    }
    print();
}
