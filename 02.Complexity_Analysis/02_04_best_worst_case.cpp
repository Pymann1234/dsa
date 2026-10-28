#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

vector<int> makeShuffledSequence(int n, mt19937& generator) {
    vector<int> values(n);
    iota(values.begin(), values.end(), 1);
    shuffle(values.begin(), values.end(), generator);
    return values;
}

int findOne(const vector<int>& values, int& inspected) {
    inspected = 0;
    for (int index = 0; index < static_cast<int>(values.size()); ++index) {
        ++inspected;
        if (values[index] == 1) {
            return index;
        }
    }
    return -1;
}

int main() {
    int n = 0;
    if (!(cin >> n) || n <= 0) {
        cerr << "Enter a positive integer.\n";
        return 1;
    }
    if (n > 1000000) {
        cerr << "Use n <= 1000000.\n";
        return 1;
    }

    mt19937 generator(random_device{}());
    auto values = makeShuffledSequence(n, generator);
    int inspected = 0;
    const int index = findOne(values, inspected);

    cout << "Index of 1 in shuffled sequence: " << index << '\n';
    cout << "Elements inspected: " << inspected << '\n';
    cout << "Best case: 1 inspection (O(1)); worst case: n inspections (O(n)).\n";
    cout << "For a uniformly shuffled sequence, expected inspections are "
              << (static_cast<double>(n) + 1.0) / 2.0 << " (Theta(n)).\n";
}
