#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
long N;

int dfs(string s)
{
    if (stol(s) > N){
        return 0;
    }

    string target = "753";
    long count = 0;
    long ret = 0;
    for(int i=0; i<target.length(); i++){
        if(s.find(target[i]) != string::npos){
            count++;
        }
    }
    if(count == 3) ret = 1;

    for(int i=0; i<target.length(); i++){
        string c;
        c = target[i];
        ret += dfs(s+c);
    }
    return ret;
}

int main()
{
    cin >> N;
    long ans = dfs("0");
    cout << ans;
}
