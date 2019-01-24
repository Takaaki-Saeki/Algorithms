#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int ans;
    if(K % 2 != 0){
        int p = N / K;
        if(p == 1) ans = 1;
        else ans = p*(p-1)*(p-2) + 3*p*(p-1) + p;
    }else{
        if((K / 2) % 2 == 0){_
            int q = N / (K / 2);
            if(q == 1) ans = 1;
            else ans = q*(q-1)*(q-2) + 3*q*(q-1) + q;
        }else{
            int r = N / (K / 2);
            int a = r / 2;
            int b = r - a;
            int ans1, ans2;
            if(a == 1) ans1 = 1;
            else ans1 = a*(a-1)*(a-2) + 3*a*(a-1) + a;

            if(b == 1) ans2 = 1;
            else ans2 = b*(b-1)*(b-2) + 3*b*(b-1) + b;
            ans = ans1 + ans2;
        }
    }
    cout << ans;
}
