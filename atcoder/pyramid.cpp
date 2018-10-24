#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int x[100];
    int y[100];
    int h[100];

    int H;
    int C_x;
    int C_y;

    for(int i=0; i<N; i++){
        int temp_x;
        int temp_y;
        int temp_h;
        scanf("%d", &temp_x);
        scanf("%d", &temp_y);
        scanf("%d", &temp_h);

        x[i] = temp_x;
        y[i] = temp_y;
        h[i] = temp_h;
    }

    if (N==1){
        H = h[0];
        C_x = x[0];
        C_y = y[0];
    }else{
        int in = -1;
        for(int i=0; i<N; i++){
            if (h[i]!=0) in = i;
        }
        if (in==-1){
            H = 0;
            C_x = x[0];
            C_y = y[0];
        }else{
            int flag;
            int in_x = 0;
            int in_y = 0;
            for(int itrx=0; itrx<=100; itrx++){
                for(int itry=0; itry<=100; itry++){
                    flag=1;
                    for(int i=0; i<N; i++){
                        C_x = itrx;
                        C_y = itry;
                        H = h[in] + abs(x[in]-C_x) + abs(y[in]-C_y);
                        if(h[i]==0){
                            if ((H-abs(x[i]-C_x)-abs(y[i]-C_y))<=0) flag = flag*1;
                            else flag = flag*0;
                        }else{
                            if((H-abs(x[i]-C_x)-abs(y[i]-C_y))==h[i]) flag = flag*1;
                            else flag = flag*0;
                        }
                    }
                    if (flag==1){
                        in_x = itrx;
                        in_y = itry;
                        goto LABEL;
                    }
                }
            }
        LABEL:
            H = h[in] + abs(x[in]-in_x) + abs(y[in]-in_y);
            C_x = in_x;
            C_y = in_y;
        }
    }
    cout << C_x << " " << C_y << " "<< H;
    return 0;
}
