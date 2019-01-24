#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int K;
    cin >> K;
    vector<string> v;

    for(int i=0; i<s.length(); i++){
        for(int j=1; j<=5; j++){
        v.push_back(s.substr(i, j));
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v[K];
}

