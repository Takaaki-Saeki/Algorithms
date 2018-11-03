#include <vecoter>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int N;
    int K;

    scanf("%d", &N);
    scanf("%d", &K);

    int counter = 0;

    if(N/K == 1) counter ++;
    else if(N/K < 2) counter += 2;
    else{
        int m = N-K;
        counter += m / (K-1) + 1;
    }

    cout << counter;

}
