#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int i = 1;
  while(n>0){
    if(i + i + 1 <= n){
      summands.push_back(i);
      n -= i;
      i++;
    }
    else{
      break;
    }
  }
  summands.push_back(n);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
