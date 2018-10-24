#include <iostream>
#include <cstdio>
#include <string>


using namespace std;

auto main()
{
    int N;
    int T;
    scanf("%d", &N);
    scanf("%d", &T);
    int v[100][2];

    for(int i=0; i<N; i++){
        char temp[100];
        string s1;
        string s2;
        scanf("%s", temp);
        s1 = temp;
        scanf("%s", temp);
        s2 = temp;

        v[i][0] = atoi(s1.c_str());
        v[i][1] = atoi(s2.c_str());
        }

    int min_cost = 10000;
    for(int i=0; i<N; i++){
        if ((v[i][0] < min_cost)&&(v[i][1] <= T)){
            min_cost = v[i][0];
            }
        }
    if (min_cost == 10000) printf("TLE");
    else printf("%d", &min_cost);

    return 0;
}
