#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int v[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> v[i][j];
        }
    }
    for(int i=1; i<3; i++){
        for(int j=0; j<3; j++){
            v[i][j] = v[i][j] - v[1][j];
        }
    }

    int judge = 1;
    for(int i=0; i<2; i++){
        if(v[i][0]==v[i][1] && v[i][1]==v[i][2]) judge*=1;
        else judge*=0;
        }
    }

    if(judge == 1) cout << "Yes";
    else cout << "No";
}
