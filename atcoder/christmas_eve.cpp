#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int N;
    int K;
    vector<long> h(N);
    cin >> N;
    cin >> K;

    for(int i=0; i<N; i++){
        long t;
        cin >> t;
        h[i] = t;
    }

    sort(h.begin(), h.end(), std::greater<long>());


    long min_sub = pow(10, 9);
    for(int i=0; i<N-K+1; i++){
        long temp = h[i] - h[i+K-1];
        if (temp < min_sub) min_sub = temp;
    }
    cout << min_sub;
}
