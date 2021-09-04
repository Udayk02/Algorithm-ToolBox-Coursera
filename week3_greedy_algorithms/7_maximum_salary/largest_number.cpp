#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::stringstream;

bool max_(string a, string b){
  stringstream x(a+b);
  int a1; x >> a1;
  stringstream y(b+a);
  int a2; y >> a2;
  if(a1 > a2){
    return true;
  }
  return false;
}

string largest_number(vector<string> a) {
  string result;
  while(!a.empty()){
    string max = a[0];
    for(int i = 0;i<a.size();++i){
      if(max_(a[i], max)){
        max = a[i];
      }
    }
    result.append(max);
    for(auto i = a.begin();i<a.end();++i){
      if(*i == max){
        a.erase(i);
        break;
      }
    }
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
