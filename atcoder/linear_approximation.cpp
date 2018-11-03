#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  scanf("%d", &N);
  vector<long long> A (N);

  for(int i=0; i<N; i++){
      long long tmp;
      scanf("%d", &tmp);
      A[i] = tmp - (i+1);
  }
  long long min_sor=0;
  long long med;

  sort(A.begin(), A.end());

  if(N%2==1){
      int med_idx = (N-1)/2;
      med = A[med_idx];
  }else{
      med = (A[N/2 -1] + A[N/2]) / 2;
  }

  for(int i=0; i<N; i++){
      min_sor += abs(A[i]-med);
  }
  cout << min_sor;

  return 0;

}
