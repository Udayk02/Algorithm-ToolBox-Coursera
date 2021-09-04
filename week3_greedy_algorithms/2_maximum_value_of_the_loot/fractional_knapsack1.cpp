#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0000;

  for(int k = 0;k<weights.size();++k){
    if(capacity==0){
      return value;
    }
    int max = 0;
    for(int i = 0;i<weights.size();++i){
      if(weights[i]>0){
        if(values[max]/weights[max] < values[i]/weights[i]){
          max = i;
        }
      }
    }
    double a = capacity < weights[max] ? capacity : weights[max];
    value += a * double(values[max])/double(weights[max]);
    capacity -= a;
    weights[max] = values[max] = 0;    
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(7);
  std::cout << optimal_value << std::endl;
  return 0;
}
