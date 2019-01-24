#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> h(N);
    for(int i=0; i<N; i++) cin >> h[i];

    int ans = 0;
    int judge = 1;
    int counter = 0;
    while(1){
        for(int i=0; i<N; i++){
            if (h[i] == 0) judge *= 1;
            else jugde *= 0;
        }

        int num;
        int cnum;
        if (h[0] == 0) num++;
        for(int i=1; i<N; i++){
            if((h[i] == 0) && (h[i-1] != 0)) num++;
        }
        if((h[0] == 0) && (h[N-1] == 0)) cnum = num - 1;
        else if((h[0] == 0)&&(h[N-1] != 0)) cnum = num;
        else if((h[0] != 0)&&(h[N-1] == 0)) cnum = num;
        else cnum = num + 1;

        if(judge == 1){
            break;
        }else{
            ans++;
            ans += cnum;
        }

        for(int i=0; i<N; i++) h[i] = h[i] - 1;
    }

    cout << ans;
}


