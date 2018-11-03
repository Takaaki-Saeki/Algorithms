#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int C[6];
    int A;
    int V[6] = {1,5,10,50,100,500};

    for(int i=0; i<6; i++){
        scanf("%d", C[i]);
    }
    scanf("%d", &A);
    int min=0;

    for(int i=0; i<6; i++){
        int tmp = min(A/V[i], C[i]);
        A -= tmp*V[i];
        min += tmp;
    }

    cout << tmp;

    return 0;

}
