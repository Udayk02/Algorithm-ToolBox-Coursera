#include <algorithm>
#include <climits>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class part
{
  public:
  int start, end;
};

vector<int> optimal_points(vector<part> &parts)
{
  vector<int> points;
  sort(parts.begin(), parts.end(),
            [](const part &a, const part &b) { return a.end < b.end; });
  vector<bool> covered(parts.size(), false);
  int point = -1;
  int j = 0;
  for (size_t i = 0; i < parts.size(); ++i)
  {
    if (not covered[i])
    {
      point = parts[i].end;
      points.push_back(point);
      covered[i] = true;
      j = i + 1;
      while (j < parts.size() && (parts[j].start <= point && parts[j].end >= point))
      {
        covered[j] = true;
        j++;
      }
    }
  }
  return points;
}

int main()
{
  int n;
  cin >> n;
  vector<part> parts(n);
  for (size_t i = 0; i < parts.size(); ++i)
  {
    cin >> parts[i].start >> parts[i].end;
  }
  vector<int> points = optimal_points(parts);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    cout << points[i] << " ";
  }
}