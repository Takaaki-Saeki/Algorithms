#include<iostream>
#include<vector>

using namespace std;

int gcd(long a, long b)
{
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    int N;
    long X;
    cin >> N >> X;

    vector<long> x(N);
    vector<long> y(N);

    for(int i=0; i<N; i++){
        cin >> x[i];
    }

    for(int i=0; i<N; i++){
        y[i] = abs(x[i] - X);
    }

    long ans = y[0];
    for(int i=1; i<N; i++){
        ans = gcd(ans, y[i]);
    }

    cout << ans;
}
