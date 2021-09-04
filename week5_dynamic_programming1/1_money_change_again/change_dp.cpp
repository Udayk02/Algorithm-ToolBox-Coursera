#include <iostream>
#include <vector>
using std::vector;

int get_change(vector<int> coins, long long m) {
  vector<long long> minNumCoins(m+1);
  minNumCoins[0] = 0;
  for(int i = 1;i<=m;++i){
    minNumCoins[i] = 99999;
    for(int j = 0;j<coins.size();++j){
      if(coins[j] <= i){
        int numCoins = minNumCoins[i - coins[j]] + 1;
        if(numCoins < minNumCoins[i]){
          minNumCoins[i] = numCoins;
        }
      }
    }
  }
  return minNumCoins[m];
}

int main() {
  long long m;
  vector<int> coins = {1, 3, 4};
  std::cin >> m;
  std::cout << get_change(coins, m) << '\n';
}
