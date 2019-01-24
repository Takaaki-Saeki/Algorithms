#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());

    int A, B, C;
    A = v[0];
    B = v[1];
    C = v[2];

    int temp = C - B;
    int ans = C - B;
    int res = C - (A+temp);

    if(res % 2 == 0) ans += res/2;
    else ans += (res+1)/2 + 1;

    cout << ans;
}
