#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v(3);
    for(int i=0; i<3; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int ans = v[0] * v[1] / 2;

    cout << ans;
}
