#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> lcs2(vector<int> &a, vector<int> &b) {
  long long arr[a.size()+1][b.size()+1];
  vector<int> sequence;
  for(int i = 0;i<=b.size();++i){
    arr[0][i] = 0;
  }
  for(int i = 0;i<=a.size();++i){
    arr[i][0] = 0;
  }
  for(int i = 1;i<=a.size();++i){
    for(int j = 1;j<=b.size();++j){
      if(a[i-1] == b[j-1]){
        arr[i][j] = arr[i-1][j-1] + 1;
      }
      else{
        arr[i][j] = std::max(arr[i-1][j], arr[i][j-1]);
      }
    }
  }
  int i = a.size(), j = b.size();
  while(arr[i][j]!=0){
    if(arr[i-1][j] < arr[i][j] && arr[i][j-1] < arr[i][j]){
      sequence.push_back(a[i-1]);
      i = i-1; j = j-1;
    }
    else if(arr[i-1][j] == arr[i][j]){
      i = i - 1;
    }
    else if(arr[i][j-1] == arr[i][j]){
      j = j - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  vector<int> sequence = lcs2(a, b);
  vector<int> final1 = lcs2(sequence, c);
  sequence = lcs2(b, c);
  vector<int> final2 = lcs2(sequence, a);
  sequence = lcs2(a, c);
  vector<int> final3 = lcs2(sequence, b);
  return std::max(std::max(final1.size(), final2.size()), final3.size());  
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
