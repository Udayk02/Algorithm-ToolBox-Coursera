#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int count = 0;
    int current = 0;
    stops.insert(stops.begin(), 0);
    stops.insert(stops.end(), dist);
    while(current<stops.size()-1){
        int last = current;
        while(current<stops.size()-1 && stops[current+1] - stops[last] <= tank){
            current++;
        }
        if (current == last){
            return -1;
        }
        if (current<stops.size()-1){
            count++;
        }
    }
    return count;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
