#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int count = 0;
  while(count<segments.size()){
    int min;
    for(int i = 0;i<segments.size();++i){
      if(segments[i].end!=0){
        min = i;
        break;
      }
    }
    for(int i = 0;i<segments.size();++i){
      if(segments[min].end > segments[i].end && segments[i].end!=0){
        min = i; 
      }
    }
    count++;
    points.push_back(segments[min].end);
    for(int i = 0;i<segments.size();++i){
      if(segments[min].end>=segments[i].start&&i!=min){
        count++;
        segments[i].start = segments[i].end = 0;
      }
    }
    segments[min].start = segments[min].end =  0;
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
