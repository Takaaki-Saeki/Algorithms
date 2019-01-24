#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long> v(6, 0);
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        if(s[0]=='M') v[0]++;
        if(s[0]=='A') v[1]++;
        if(s[0]=='R') v[2]++;
        if(s[0]=='C') v[3]++;
        if(s[0]=='H') v[4]++;
    }

    int cnt=0;
    for(int i=0; i<5; i++){
        if(v[i]==0) cnt++;
    }
    sort(v.begin(), v.end(), std::greater<int>());
    long ans=0;
    if(cnt >= 3){
        ans = 0;
    }else{
        if(cnt==0){
            ans += v[0]*v[1]*v[2]+v[0]*v[2]*v[3]+v[0]*v[3]*v[4];
            ans += v[0]*v[1]*v[3]+v[0]*v[1]*v[4]+v[0]*v[2]*v[4];
            ans += v[1]*v[2]*v[3]+v[1]*v[3]*v[4]+v[1]*v[2]*v[4];
            ans += v[2]*v[3]*v[4];
        }else if(cnt==1){
            ans += v[0]*v[1]*v[2]+v[0]*v[2]*v[3]+v[0]*v[1]*v[3];
            ans += v[1]*v[2]*v[3];
        }else{
            ans = v[0]*v[1]*v[2];
        }
    }
    cout << ans;
}
