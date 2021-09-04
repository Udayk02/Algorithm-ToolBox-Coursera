#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<long long> subset(vector<long long> A, long long sum){
  long long dp[A.size()+1][sum + 1];
  vector<long long> arr;
  for(long long i = 0;i<=A.size();++i){
    dp[i][0] = 1;
  }
  for(long long i = 1;i<=sum;++i){
    dp[0][i] = 0;
  }
  for(long long i = 1;i<=A.size();++i){
    for(long long j = 1;j<=sum;++j){
      dp[i][j] = dp[i-1][j];
      if(A[i-1]<=j){
        dp[i][j] = dp[i][j] || dp[i-1][j-A[i-1]];
      }
    }
  }
  if(dp[A.size()][sum]==1){
    long long i = A.size(), j = sum;
    while(i!=0){
      if(dp[i-1][j]==1){
        i = i - 1;
      }
      else{
        arr.push_back(A[i-1]);
        j = j - A[i-1];
        i = i - 1;
      }
    }
    for(long long i = 0;i<arr.size();++i){
      auto j = A.begin();
      for(j;j<A.end();++j){
        if(*j==arr[i]){
          break;
        }
      }
      A.erase(j);
    }
    return A;
  }
  vector<long long> a(0);
  return a;
}

long long partition3(vector<long long> &A) {
  long long sum = 0;
  for(long long i = 0;i<A.size();++i){
    sum += A[i];
  }
  if(sum%3!=0){
    return 0;
  }
  sum = sum / 3;
  vector<long long> newA = subset(A, sum);
  if(newA.size()!=0){
    sum = 0;
    for(long long i = 0;i<newA.size();++i){
      sum += newA[i];
    }
    if(sum%2!=0){
      return 0;
    }
    sum = sum/2;
    vector<long long> B = subset(newA, sum);
    if(B.size()==0){
      return 0;
    }
    return 1;
  }
  return 0;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
