#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct Elem
{
    int num;
    int idx;
};

bool cmp(const Elem &a, const Elem &b)
{
    return a.num > b.num;
}


int main()
{
    int n;
    scanf("%d", &n);
    int a[100000];
    Elem odd[100000];
    Elem even[100000];

    for(int i=0; i<n; i++){
        int tmp;
        scanf("%d", &tmp);
        a[i] = tmp;
    }

    for (int i=0; i<=100000; i++){
        odd[i].num = 0;
        odd[i].idx = i;
        even[i].num = 0;
        even[i].idx = i;
    }

    for (int i=0; i<=(n-2)/2; i++){
        int even_tmp = a[2*i];
        int odd_tmp = a[2*i+1];
        odd[odd_tmp].num = odd[odd_tmp].num + 1;
        even[even_tmp].num = even[even_tmp].num + 1;
    }
    sort(odd, odd+100000,cmp);
    sort(even, even+100000, cmp);

    int odd_max;
    int even_max;

    if(odd[0].idx == even[0].idx){
        if (odd[1].num >= even[1].num){
            odd_max = odd[1].idx;
            even_max = even[0].idx;
        }else{
            odd_max = odd[0].idx;
            even_max = even[1].idx;
        }
    }else{
        odd_max = odd[0].idx;
        even_max = even[0].idx;
    }

    int counter = 0;
    int flag = 0;

    while(true){
        if(odd[flag].idx!=odd_max) counter = counter + odd[flag].num;
        if(even[flag].idx!=even_max) counter = counter + even[flag].num;
        if((odd[flag].num==0)&&(even[flag].num==0)) break;
        flag++;
    }

    cout << counter;

    return 0;

}
