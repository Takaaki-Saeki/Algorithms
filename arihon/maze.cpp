#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

class Pos{
public:
    int i;
    int j;
};

int N;
int M;
int v[N][M];
int d[N][M];
int distance=0;
int c[N][M];
queue<Pos> q;

void BFS(int k, int l)
{
    Pos tmp;
    int i = k;
    int j = l;
    c[i][j] = 2;
    d[i][j] = 0;
    while(ture){
        if((i<N-1)&&(v[i+1][j]==0)&&(c[i+1][j]==0)){
            tmp.i = i+1;
            tmp.j = j;
            q.push(tmp);
            c[i+1][j] = 1;
            d[i+1][j] = d[i][j] + 1;
            continue;
        }
        if((i>0)&&(v[i-1][j]==0)&&(c[i-1][j]==0)){
            tmp.i = i-1;
            tmp.j = j;
            q.push(tmp);
            c[i-1][j] = 1;
            d[i-1][j] = d[i][j] + 1;
            continue;
        }
        if((j<M-1)&&(v[i][j+1]==0)&&(c[i][j+1]==0)){
            tmp.i = i;
            tmp.j = j+1;
            q.push(tmp);
            c[i][j+1] = 1;
            d[i][j+1] = d[i][j] + 1;
            continue;
        }
        if((j>0)&&(v[i][j-1]==0)&&(c[i][j-1]==0)){
            tmp.i = i;
            tmp.j = j-1;
            q.push(tmp);
            c[i][j-1] = 1;
            d[i][j-1] = d[i][j] + 1;
            continue;
        }
        if((i<N-1)&&(v[i+1][j]==3)&&(c[i+1][j]==0)){
            d[i+1][j] = d[i][j] + 1;
            cout << d[i+1][j];
            break;
        }
        if((i>0)&&(v[i-1][j]==3)&&(c[i-1][j]==0)){
            d[i-1][j] = d[i][j] + 1;
            cout << d[i-1][j];
            break;
        }
        if((j<M-1)&&(v[i][j+1]==3)&&(c[i][j+1]==0)){
            d[i][j+1] = d[i][j] + 1;
            cout << d[i][j+1];
            break;
        }
        if((j>0)&&(v[i][j-1]==3)&&(c[i][j-1]==0)){
            d[i][j-1] = d[i][j] - 1;
            cout << d[i][j-1];
            break;
        }

        tmp = q.front();
        q.pop();
        i = tmp.i;
        j = tmp.j;
        c[i][j] = 2;
        continue;
    }
}




int main()
{
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char tmp;
            scanf(" %c", &tmp);
            if(tmp == '.') v[i][j] = 0;
            else if(tmp == '#') v[i][j] = 1;
            else if(tmp == 's') v[i][j] = 2;
            else if(tmp == 'g') v[i][j] = 3;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            c[i][j] = 0
        }
    }

    int k;
    int l;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if (v[i][j]==2){
                k = i;
                l = j;
            }
        }
    }
    BFS(k, l);

    return 0;

}
