#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N;
    vector<int> a;

    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    long m=0;

    for(int i=0; i<N; i++){
        m += (a[i] - 1);
    }

    cout << m;

    return 0;
}
