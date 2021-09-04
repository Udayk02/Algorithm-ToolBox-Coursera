#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, vector<int> &b, int mid, size_t left, size_t right){
  int l = mid - left + 1;
  int r = right - mid;
  vector<int> L(l);
  vector<int> R(r);
  for(int i = 0;i<l;++i){
    L.push_back(a[left+i]);
  }
  for(int i = 0;i<r;++i){
    R.push_back(a[mid+1+i]);
  }
  int i = 0, j = 0, k = left, count = 0; 
  while(i < left && j < right){
    if(L[i]<=R[j]){
      b.push_back(L[i]);
      i++;
    }
    else{
      b.push_back(R[j]);
      j++; count++;
    }
  }
  while(i<l){
    b.push_back(L[i]);
    i++;
  }
  while(j<r){
    b.push_back(R[j]);
    j++;
  }
  return count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  number_of_inversions += merge(a, b, ave, left, right);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
