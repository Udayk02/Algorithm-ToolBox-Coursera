#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence_efficient(int n){
  if(n==1){
    vector<int> sequence = {1};
    return sequence;
  }
  std::vector<int> minimum(n + 1);
  std::vector<int> prev(n + 1);
  for(int i = 0;i <= n;++i){
    prev[i] = -1;
  }
  std::vector<int> sequence;
  minimum[0] = minimum[1] = 0;
  for(int i = 2;i<=n;++i){
    int min = INT8_MAX;
    if(i % 2 == 0){
      if(min > minimum[i/2] + 1){
        min = minimum[i/2] + 1;
        prev[i] = i/2;
      }
    }
    if(i % 3 == 0){
      if(min > minimum[i/3] + 1){
        min = minimum[i/3] + 1;
        prev[i] = i/3;
      }
    }
    if(min > minimum[i-1] + 1){
      min = minimum[i-1] + 1;
      prev[i] = i-1;
    }
    minimum[i] = min;
  }
  int i = n;
  sequence.push_back(i);
  while(prev[i]!=1){
    sequence.push_back(prev[i]);
    i = prev[i];
  }
  sequence.push_back(1);
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_efficient(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}