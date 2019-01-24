#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binary_search(vector<P> &x, long X, int b, int e)
{
    int mid = (b + e) / 2;
    if(x[mid].second == X) return mid;
    else if(x[mid].second > X) return binary_search(x, X, b, mid);
    else if(x[mid].second < X) return binary_search(x, X, mid, e);
}

int main()
{
    int N;
    cin >> N;

    vector<long> x(N);
    vector<long> y(N);

    for(int i=0; i<N; i++){
        long temp;
        cin >> temp;
        x[i] = temp;
        y[i] = temp;
    }

    sort(x.begin(),x.end());

    for(int i=0; i<N; i++){
        long med;
        long X = y[i];
        if(X <= x[N/2 - 1]) med = x[N/2];
        else med = x[N/2 - 1];

        if(i < N-1) cout << "med" << "\n";
        else cout << med;
    }
}
