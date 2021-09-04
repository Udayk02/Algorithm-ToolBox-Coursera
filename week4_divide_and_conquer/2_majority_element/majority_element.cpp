#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<long long> &a, int left, int right) {
  if (left == right) return 0;
  if (left + 1 == right) return 1;
  sort(a.begin(), a.end());
  int count = 0;
  for(int i = 0;i<a.size();++i){
    if(i==0){
      count = 1;
    }
    else if(a[i]==a[i-1]){
      count++;
    }
    else{
      count = 1;
    }
    if(count > (a.size()/2)){
      return 1;
    }
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  int result = get_majority_element(a, 0, a.size());
  std::cout << result << '\n';
}
