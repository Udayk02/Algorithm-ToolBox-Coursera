#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class loot
{
private:
    int weight;
    int value;

public:
    loot(int value, int weight) : value(value), weight(weight) {}
    ~loot() = default;
    loot() = delete;
    int getWeight() { return weight; }

    int getValue() { return value; }

    double getValueOfloot(int items = 1) const
    {
        return static_cast<double>(value * items) / weight;
    }

    bool operator<(const loot &a)
    {
        return getValueOfloot() < a.getValueOfloot();
    }
};

double get_optimal_value(int capacity, vector<loot> &items)
{
    double value = 0.0;
    sort(items.begin(), items.end());
    reverse(items.begin(), items.end());
    auto it = items.begin();
    while (capacity > 0)
    {
        if (capacity >= it->getWeight())
        {
            capacity -= it->getWeight();
            value += it->getValue();
        }
        else
        {
            value += it->getValueOfloot(capacity);
            capacity = 0;
        }
        it = next(it);
    }

    return value;
}

int main()
{
    int n;
    int capacity;
    cin >> n >> capacity;

    vector<loot> items;
    int value, weight;

    for (int i = 0; i < n; i++)
    {
        cin >> value >> weight;
        items.emplace_back(value, weight);
    }

    double optimal_value = get_optimal_value(capacity, items);

    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}