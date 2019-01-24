#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dev(long p, long c)
{
    if(p % 2 == 0){
        return c;
    }else{
        return dev(p/2, ++c);
    }
}

int main()
{
    int N;
    cin >> N;

    vector<long> a(N);

    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    long counter = 0;
    for(int i=0; i<N; i++){
        counter += dev(a[i], 0);
    }

    cout << counter;
}
