##include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int N;
    int K;

    scanf("%d", &N);
    scanf("%d", &K);

    vector<long long> X(N);

    for(int i=0; i<N; i++){
        long long tmp;
        scanf("%lld", &tmp);
        X[i] = tmp;
    }
    long long min_d = 1000000000;

    for(int i=0; i<=N-K; i++){
        long long d = min((X[i+K-1] - X[i]+abs(X[i+K-1])), (X[i+K-1]-X[i]+abs(X[i])));
        if (d < min_d) min_d = d;
    }

    cout << min_d;

    return 0;
}
