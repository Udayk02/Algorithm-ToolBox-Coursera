#include <iostream>
#include <vector>

using std::vector;

long long optimal_weight_dp(long long W, const vector<long long> &w) {
  vector<vector<long long>> dp(w.size()+1, vector<long long>(W+1));
  for(long long i = 0;i<=w.size();++i){
    dp[i][0] = 0;
  }
  for(long long i = 0;i<=W;++i){
    dp[0][i] = 0;
  }
  for(long long i = 1;i<=w.size();++i){
    for(long long j = 1;j<=W;++j){
      if(w[i-1] <= j){
        dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-w[i-1]] + w[i-1]);
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[w.size()][W];
}

// long long optimal_weight(long long W, const vector<long long> &w) {
//   //write your code here
//   long long current_weight = 0;
//   for (size_t i = 0; i < w.size(); ++i) {
//     if (current_weight + w[i] <= W) {
//       current_weight += w[i];
//     }
//   }
//   return current_weight;
// }

int main() {
  long long n, W;
  std::cin >> W >> n;
  vector<long long> w(n);
  for (long long i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight_dp(W, w) << '\n';
}