// 深さ優先探索を用いて湖の数を数える
// 縦横斜めで隣り合っているwはつながっているものと見なす
// 例えば、このような場合は3つ
// ...www...ww
// ..ww...w..w
//....www..www
//..........w.
//..........ww

#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

struct Loc{
    int i;
    int j;
};

int v[100][100];
int c[100][100];
stack<Loc> s;
int N;
int M;
int counter;


void DFS(int i, int j)
{
    Loc tmp;
    c[i][j] = 1;
    while(true){
        if((i<N-1)&&(c[i+1][j]==0)&&(v[i+1][j]==1)){
            tmp.i = i+1;
            tmp.j = j;
            s.push(tmp);
            i=i+1;
            c[i][j] = 1;
            continue;
        }
        if((i<N-1)&&(j>0)&&(c[i+1][j-1]==0)&&(v[i+1][j-1]==1)){
            tmp.i = i+1;
            tmp.j = j-1;
            s.push(tmp);
            i = i+1;
            j = j-1;
            c[i][j] = 1;
            continue;
        }
        if((j>0)&&(c[i][j-1]==0)&&(v[i][j-1]==1)){
            tmp.i = i;
            tmp.j = j-1;
            s.push(tmp);
            j = j-1;
            c[i][j] = 1;
            continue;
        }
        if((i>0)&&(j>0)&&(c[i-1][j-1]==0)&&(v[i-1][j-1]==1)){
            tmp.i = i-1;
            tmp.j = j-1;
            s.push(tmp);
            i = i-1;
            j = j-1;
            c[i][j] = 1;
            continue;
        }
        if((i>0)&&(c[i-1][j]==0)&&(v[i-1][j]==1)){
            tmp.i = i-1;
            tmp.j = j;
            s.push(tmp);
            i = i-1;
            c[i][j] = 1;
            continue;
        }
        if((i>0)&&(j<M-1)&&(c[i-1][j+1]==0)&&(v[i-1][j+1]==1)){
            tmp.i = i-1;
            tmp.j = j+1;
            s.push(tmp);
            i = i-1;
            j = j+1;
            c[i][j] = 1;
            continue;
        }
        if((j<M-1)&&(c[i][j+1]==0)&&(v[i][j+1]==1)){
            tmp.i = i;
            tmp.j = j+1;
            s.push(tmp);
            j = j+1;
            c[i][j] = 1;
            continue;
        }
        if((i<N-1)&&(j<M-1)&&(c[i+1][j+1]==0)&&(v[i+1][j+1]==1)){
            tmp.i = i+1;
            tmp.j = j+1;
            s.push(tmp);
            i = i+1;
            j = j+1;
            c[i][j] = 1;
            continue;
        }
        if (s.empty()){
            break;
        }else{
            Loc temp = s.top();
            s.pop();
            c[temp.i][temp.j] = 2;
            i = temp.i;
            j = temp.j;
       }
    }
}


int main()
{
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char tmp;
            scanf(" %c", &tmp);
            if(tmp=='.') v[i][j] = 0;
            else if (tmp == 'w') v[i][j] = 1;
        }
    }

    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            c[i][j] = 0;
        }
    }

    counter = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if ((c[i][j] == 0)&&(v[i][j]==1)){
                counter++;
                DFS(i, j);
            }
        }
    }

    cout << counter;
    return 0;

}
