#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N;
     cin >> N;
     vector<vector<int>> A;
     vector<vector<int>> B;
     A.resize(2);
     B.resize(2);
     B[0].resize(N);
     B[1].resize(N);

     for(int n=0; n<2; n++){
        for(int i=0; i<N; i++){
            int temp;
            cin >> temp;
            A[n].push_back(temp);
        }
     }
     B[0][0] = A[0][0];
     for(int i=1; i<N; i++){
        B[0][i] = B[0][i-1] + A[0][i];
     }
     B[1][N-1] = A[1][N-1];
     for(int i=N-2; i>=0; i--){
        B[1][i] = B[1][i+1] + A[1][i];
     }

     int max_num = 0;
     for(int i=0; i<N; i++){
        if(B[0][i]+B[1][i] >= max_num) max_num = B[0][i]+B[1][i];
     }

     cout << max_num;
}
