#include<iostream>
#include<vector>

using namespace std;

int solve(int res, int count, int D, int sum, vector<int> &v, vector<int> &p)
{
    if(res == 0) {
        for(int i=D-1; i>=0; i--){
            int P =0;
            while((P < p[i]) ||  sum >= G)){
                P++;
                count++;
                sum += 100*(i+1);
            }
        }
        return count;
    }






}

int main()
{





}
