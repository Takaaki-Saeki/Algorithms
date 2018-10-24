#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int ans;
    if (n/100 == 9) ans = 100;
    else ans = 900;

    n_temp = n/10;
    if(n_temp%10==9) ans = ans + 10;
    else ans = ans + 90;

    if (n%10 == 9) ans = ans+1;
    else ans = ans + 9;

    cout << ans;

    return 0;


}
