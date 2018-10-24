#include <cstdio>
#include <iostream>

using namespace std;

class Cd{
public:
  int x;
  int y;

};

int N;
Cd p[1000];
long long num[1000000000000];
int flag = 0;
long long x[40];
int x_op[40];
long long y[40];
int y_op[40];

void sum()
{







}


int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        int tmp_x;
        int tmp_Y;
        scanf("%d", &tmp_x);
        scanf("%d", &tmp_y);
        Cd tmp;
        tmp.x = tmp_x;
        tmp.y = tmp_y;
        p[i] = tmp;
    }

    for(long long i=1; i<=1000000000000; i++){
        num[i] = i;
    }



    return 0;

}
