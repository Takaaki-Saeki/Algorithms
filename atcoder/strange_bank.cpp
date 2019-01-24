#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    long inf = 1000000000;
    int N;
    cin >> N;
    vector<int> dp(N+1);

    for(int i=0; i<=N; i++) dp[i] = inf;

    dp[0] = 0;

    for(int i=1; i<=N; i++){
        int power = 1;
        while(power <= i){
            dp[i] = min(dp[i], dp[i-power]+1);
            power *= 6;
        }
        int power2 = 1;
        while(power2 <= i){
            dp[i] = min(dp[i], dp[i-power2]+1);
            power2 *= 9;
        }
    }

    cout << dp[N];
}
