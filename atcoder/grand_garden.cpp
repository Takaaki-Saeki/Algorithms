#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> h(N+2);

    h[0] = 0;
    h[N+1] = 0;
    int ans=0;
    for(int i=1; i<=N+1; i++){
        ans += max(0, h[i] - h[i-1]);
    }

    cout << ans;
}
