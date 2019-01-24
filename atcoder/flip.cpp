#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long N, M;
    long zero = 0;
    cin >> N >> M;

    long ans;

    if(N == 1){
        if(M!=1) ans = max(zero, M-2);
        else ans = 1;
    }
    if(M == 1){
        if(N!=1) ans = max(zero, N-2);
        else ans = 1;
    }

    if((N-1)*(M-1)!=0) ans = (N-2)*(M-2);

    cout << ans;
}
