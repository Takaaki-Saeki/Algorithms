#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int M;
    vector<int> v;
    int ans;

    scanf("%d", &N);
    scanf("%d", &M);

    for(int i=1; i<M/2; i++){
        if (M % i == 0){
            v.emplace_back(i);
            v.emplace_back(M/i);
        }
    }

    sort(v.begin(), v.end());

    while(1){
        int a = v.back();
        v.pop_back();
        int m = M / a;
        if (m >= N){
            ans = a;
            break;
        }
    }
    cout << ans;
    return 0;


}
