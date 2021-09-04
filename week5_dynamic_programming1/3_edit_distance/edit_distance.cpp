#include <iostream>
#include <string>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  if(str1.size()==0){
    return str2.size();
  }
  if(str2.size()==0){
    return str1.size();
  }
  if(str1 == str2){
    return 0;
  }
  long long matrix[str2.size() + 1][str1.size() + 1];
  for(long long i = 0;i<str2.size()+1;++i){
    matrix[i][0] = i;
  }
  for(long long j = 0;j<str1.size()+1;++j){
    matrix[0][j] = j;
  }
  for(long long i = 1;i<str2.size() + 1;++i){
    for(long long j = 1;j<str1.size() + 1;++j){
      if(str1[i-1]==str2[j-1]){
        matrix[i][j] = matrix[i-1][j-1];
      }
      else{
        matrix[i][j] = 1 + min(min(matrix[i][j-1], matrix[i-1][j-1]), matrix[i-1][j]);
      }
    }
  }
  return matrix[str2.size()][str1.size()];
}

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
