#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N+2);
    A[0] = 0;
    A[N+1] = 0;
    for(int i=1; i<=N; i++){
        cin >> A[i];
    }
    int sum = 0;
    for(int i=0; i<=N; i++){
        sum += abs(A[i] - A[i+1]);
    }
    for(int i=1; i<=N; i++){
        int temp1 = abs(A[i] - A[i-1]) + abs(A[i+1] - A[i]);
        int temp2 = abs(A[i+1] - A[i-1]);
        int sum_temp = sum - (temp1 - temp2);
        cout << sum_temp;
    }
}
