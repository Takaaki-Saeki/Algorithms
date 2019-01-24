#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    int v[55][55];
    for(int i=0; i<=H+1; i++){
        v[i][0] = 1;
        v[i][W+1] = 1;
    }
    for(int j=0; j<=W+1; j++){
        v[0][j] = 1;
        v[H+1][j] = 1;
    }

    for(int i=0; i<H; i++){
        string s;
        cin >> s;
        for(int j=0; j<W; j++){
            if (s[j] == '.') v[i+1][j+1] = 1;
            else if(s[j] == '#') v[i+1][j+1] = 0;
        }
    }

    int judge = 1;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
          	if(v[i][j] == 0){
              	if((v[i][j-1] * v[i][j+1] * v[i-1][j] * v[i+1][j]) == 0) judge *= 1;
            	else judge*= 0;
          	}
        }
    }

    if(judge == 1) cout << "Yes";
    else cout << "No";
}
