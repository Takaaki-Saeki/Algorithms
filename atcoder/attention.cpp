#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int N;
    int S;
    vector<int> A(N);
    vector<int> B(N);

    scanf("%d", &N);

    for (int i=0; i<N; i++){
        char tmp;
        scanf("%c", &tmp);
        if(tmp == 'E') A[i] = 1;
        else if(tmp == 'W') A[i] = 0;
    }

    B[0] = A[0];
    for(int i=1; i<N; i++){
        B[i] = B[i-1] + A[i];
    }

    int min = 1000000;

    int lef = B[N-1] - B[0];
    if(lef < min) min = lef;

    int righ = (N-1) - B[N-2];
    if(righ < min) min = righ;

    for(int i=1; i<N-1; i++){
        int left = B[i-1];
        int right = B[N-1] - B[i];
        int l_0 = i - B[i-1];
        int ans = right + l_0;
        if(ans < min) min = ans;
    }

    cout << min;

    return 0;
}
