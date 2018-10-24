#include <cstdio>
#include <iostream>


using namespace std;

int n;
int a[20];
int k;

bool sum(int i, int p)
{
    if (p == 0) return true;
    if (i > n) return false;

    return sum(i+1, p) || sum(i+1, p-a[i]);

}




int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int tmp;
        scanf("%d", &tmp);
        a[i] = tmp;
    }
    scanf("%d", &k);

    if(sum(0, k)) cout << "Yes";
    else cout << "No";

    return 0;

}
