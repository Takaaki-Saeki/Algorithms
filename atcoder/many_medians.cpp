#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int N;
    vector<long long> X(N);
    vector<long long> B(N);
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        long long tmp;
        scanf("%lld", &tmp);
        X[i] = tmp;
    }

    for(int i=0; i<N; i++){
        vector<long long> Y(N);
        copy(X.begin(), X.end(), back_inserter(Y));
        Y.erase(Y.begin()+i);
        sort(Y.begin(), Y.end());
        B[i] = Y[(N-2)/2];
    }

    for(int i=0; i<N-1; i++){
        cout << B[i] << "\n";
    }
    cout << B[N-1];

    return 0;
}
