#include<iostream>
#include<vector>

using namespace std;

string search(long N, string s)
{
    int prev = -1;
    int p;

    while(N != 0){
        int lower = 0;
        int upper = 0;

        for(int i=0; i<28; i++){
            for(int j=0; j<=i; j++){
                if(j % 2 == 0) lower += pow(-2, j);
                else upper += pow(-2, j);
            }
            if(N >= lower && N <= upper){
                p = i;
                if (prev == -1){
                    s += '1';
                    N -= pow(-2, p);
                }else{
                    string zero(prev - p, '0');
                    s += zero;
                    N -= pow(-2, p);
                }
                prev = i;
                break;
            }
        }
    }

    return s;
}

int main()
{
    long N;
    string str = "";
    string ans = search(N, str);
    cout << ans;
}

