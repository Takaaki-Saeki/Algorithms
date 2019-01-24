#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<long> Y(M);
    vector<int> P(M);
    vector<long> A(N+1);

    for(int i=0; i<M; i++){
        cin >> P[i];
        cin >> Y[i];
        A[P[i]].push_back(Y[i]);
    }

    for(int i=1; i<=N; i++){
        sort(A[i].begin(), A[i].end());
    }

    for(int i=0; i<M; i++){
        auto itr = lower_bound(A[P[i]].begin(), A[P[i]].end(), Y[i]);
        string s1 = to_string(A[i]);
        string s2 = to_string(itr);
        string t1 = ((6-s1.length()), '0');
        string t2 = ((6-s2.length()), '0');
        string ans = t1 + s1 + t2 + s2;
        cout << ans;
    }
}
