#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N;
    cin >> S;
    vector<int> v(N, 0);

    if(S[0] == 'E') v[0] = 1;
    for(int i=1; i<N; i++){
        if(S[i] == 'E') v[i] = 1;
        v[i] = v[i] + v[i-1];
    }

    int a1 = v[N-1] - v[0];
    int a2 = (N-1) - v[N-2];
    int ans = min(a1, a2);
    for(int i=1; i<N-1; i++){
        int a3 =  i + v[N-1] - v[i] - v[i-1];
        ans = min(ans, a3);
    }
    cout << ans;
}
