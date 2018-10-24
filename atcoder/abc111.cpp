#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int min = 1000;
    int min_idx = -1;


    for (int i=1; i<10; i++){
        int val = 111*i - N;
        if(val >= 0){
            if(val < min){
                min = val;
                min_idx = i;
            }
        }
    }


    cout << min_idx*111;

    return 0;
}
