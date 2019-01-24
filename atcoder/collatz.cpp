#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int s;
    cin >> s;
    int m = 1000010;
    vector<int> v(m+1);
    v[0] = -1;
    v[1] = s;

    for(int i=1; i<m; i++){
        if(i % 2 == 0) v[i+1] = 1 / 2;
        else v[i+1] = 3 * i + 1;
    }
    int ans;
    for(int i=1; i<m; i++){
        for(int j=0; j<i; j++){
            if(v[i] == v[j]) ans = i;
        }
    }

    cout << ans;
}
