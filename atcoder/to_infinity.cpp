#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string S;
int K;
vector<int> v;

int main()
{
    cin >> S;
    cin >> K;

    for(int i=0; i<S.length(); i++){
        int temp = stoi(S[i]);
        v.push_back(temp);
    }

    int ans;
    for(int i=0; i<v.size();, i++){
        long long num = 5000 * pow(10, 12);
        long long p = pow(S[i], num);
        K = K - p;
        if(K <= 0){
            ans = S[i];
            break;
        }
    }

    cout << ans;
