#include<cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int N;
    int M;
    vector<vector<pair <int, int>>> v;
    vector<string> S(M);

    scanf("%d", N);
    scanf("%d", M);

    for(int i=0; i<M; i++){
        int p;
        int y;
        scanf("%d", &p);
        scanf("%d", &y);
        v[p].push_back({y,i});
    }

    for(int i=0; i<N; i++){
        sort(v[i].bagin(), v[i].end());

        for(int j=0; j<v[i].size(), j++){
            string l = to_string(i);
            string r = to_string(j);
            while(l.size() < 6) l = '0' + l;
            while(r.size() < 6) r = '0' + r;
            S[v[i].second] = l + r;
        }
    }

    for(int i=0; i<N-1; i++) cout << S[i] << "\n";
    cout << S[N-1];

    return 0;

}

