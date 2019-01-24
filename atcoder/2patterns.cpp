#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

typedef pair<int, int> P;

bool pairCompare(const P& firstElof, const P& secondElof)
{
        return firstElof.second > secondElof.second;
}

vector<P> ep;
vector<P> op;

int main()
{
    vector<int> ef(100005, 0);
    vector<int> of(100005, 0);
    int n;
    vector<int> e(n);
    vector<int> o(n);
    cin >> n;

    for(int i=0; i<n/2; i++){
        int e1;
        int o1;
        cin >> e1;
        cin >> o1;
        e[i] = e1;
        o[i] = o1;
    }

    for(int i=0; i<n/2; i++){
        ef[e[i]]++;
        of[o[i]]++;
    }

    for(int i=0; i<100000; i++){
        P temp1(i, ef[i]);
        ep.push_back(temp1);
        P temp2(i, of[i]);
        op.push_back(temp2);
    }

    sort(ep.begin(), ep.end(), pairCompare);
    sort(op.begin(), op.end(), pairCompare);

    int ans=0;
    if(ep[0].first != op[0].first){
        int emax = ep[0].second;
        int omax = op[0].second;
        ans = n - (emax+omax);
    }else{
        int emax1 = ep[0].second;
        int emax2 = ep[1].second;
        int omax1 = op[0].second;
        int omax2 = op[1].second;
        int case1 = n - (emax1 + omax2);
        int case2 = n - (emax2 + omax1);
        ans = min(case1, case2);
    }

    cout << ans;

    return 0;
}
