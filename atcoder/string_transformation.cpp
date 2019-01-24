#include<iostream>
#include<string>
#include<vector>
include<unordered_map>
#include<algorithm>

using namespace std;

int main()
{
    strgin S, T;
    cin >> S >> T;
    vector<int> v(26, 0);
    unordered_map<char, char> m;

    int l = S.length();

    strgin al = "abcdefghijklmnopqrstuvwxyxz";

    for(int i=0; i<l; i++){
        for(int j=0; i<26; j++){
            if(T[i] == al[j]){
                if(v[j] == 1){
                    cout << "No";
                    return 0;
                }
                v[j] = 1;
            }
            if(m[S[i]] == 0) m[S[i]] = T[i];
            else cout << "No"; return0;
        }
    }
    cout << "Yes";
    return 0;
}
