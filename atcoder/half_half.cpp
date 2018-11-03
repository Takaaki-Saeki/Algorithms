#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int A, B, C;
    int X, Y;

    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &X);
    scanf("%d", &Y);

    int m;
    if(X>=Y) m = X;
    else m = Y;

    long min_price = 1000000000;
    for(int i=m; i>=0; i--){
        int price = 0;
        price += 2*C*i;
        if(X>=i) price += A*(X-i);
        if(Y>=i) price += B*(Y-i);

        if(price < min_price){
            min_price = price;
            cout << i;
        }
    }

    cout << min_price;




}
