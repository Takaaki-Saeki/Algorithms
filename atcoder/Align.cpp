#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int A[100000];
    scanf("%d", &N);

    for(int i=0; i<N;i++){
      int tmp;
      scanf("%d", &tmp);
      A[i] = tmp;
    }
    int ans;
    sort(A,A+N);
    if(N%2==1){
        int plas=0;
        for(int i=N-1; i>=(N+1)/2; i--){
            plas = plas + 2*A[i];
        }
        int minus = 0;
        for(int i=0; i<(N+1)/2-2; i++){
            minus = minus + 2*A[i];
        }
        minus = minus + A[(N+1)/2-2];
        minus = minus + A[(N+1)/2-1];
        ans = plas - minus;
    }else{
        int plas=0;
        for(int i=N-1; i>N/2; i--){
            plas = plas + 2*A[i];
        }
        plas = plas + A[N/2];

        int minus = 0;
        for(int i=0; i<N/2-1; i++){
            minus = minus + 2*A[i];
        }
        minus = minus + A[N/2-1];
        ans = plas -minus;
    }
    cout << ans;

    return 0;

}
