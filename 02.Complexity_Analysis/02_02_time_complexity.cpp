#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int constantWork(int) {
    int operations = 0;
    for (int i = 0; i < 1000; ++i) {
        ++operations;
    }
    return operations;
}

int simpleOperationCount(int n) {
    return 3 + 2 * n;
}

int algorithmAWork(int) {
    return 1;
}

int algorithmBWork(int n) {
    return n;
}

int algorithmCWork(int) {
    return 1000000;
}

int linearWork(int n) {
    int operations = 0;
    for (int i = 0; i < n; ++i) {
        ++operations;
    }
    return operations;
}

int traversalWork(const vector<int>& values) {
    int operations = 0;
    for (int value : values) {
        (void)value;
        ++operations;
    }
    return operations;
}

int nestedLoopWork(int n) {
    int iterations = 0;
    for (int row = 0; row < n; ++row) {
        for (int column = 0; column < n; ++column) {
            ++iterations;
        }
    }
    return iterations;
}

int quadraticWork(int n) {
    int operations = 0;
    for (int row = 0; row < n; ++row) {
        for (int column = 0; column < n; ++column) {
            ++operations;
        }
    }
    return operations;
}

int bubbleSortAssignments(vector<int>& values) {
    int assignments = 0;
    for (int end = static_cast<int>(values.size()); end > 1; --end) {
        for (int index = 0; index + 1 < end; ++index) {
            if (values[index] > values[index + 1]) {
            swap(values[index], values[index + 1]);
                assignments += 3;
            }
        }
    }
    return assignments;
}

int exponentialLoopWork(int levels) {
    int operations = 0;
    int currentPopulation = 1;
    for (int level = 0; level < levels; ++level) {
        operations += currentPopulation;
        currentPopulation *= 2;
    }
    return operations;
}

int exponentialRecursiveWork(int levels) {
    if (levels == 0) {
        return 0;
    }
    return 2 * exponentialRecursiveWork(levels - 1) + 1;
}

int logarithmicLoopWork(int n) {
    int operations = 0;
    while (n > 1) {
        n /= 2;
        ++operations;
    }
    return operations;
}

int logarithmicRecursiveWork(int n) {
    if (n <= 1) {
        return 0;
    }
    return 1 + logarithmicRecursiveWork(n / 2);
}

int linearithmicRecursiveWork(int n) {
    if (n <= 1) {
        return 1;
    }
    return 2 * linearithmicRecursiveWork(n / 2) + n;
}

int factorialBranchCount(int n) {
    if (n == 0) {
        return 1;
    }
    int calls = 0;
    for (int branch = 0; branch < n; ++branch) {
        calls += factorialBranchCount(n - 1);
    }
    return calls;
}

int main() {
    int n = 0;
    if (!(cin >> n) || n < 0) {
        cerr << "Enter a non-negative integer.\n";
        return 1;
    }
    if (n > 1000) {
        cerr << "Use n <= 1000 for the quadratic example.\n";
        return 1;
    }

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        values[i] = n - i;
    }

    cout << "O(1) operations: " << constantWork(n) << '\n';
    cout << "Example operation count T(n) = 3 + 2n: "
              << simpleOperationCount(n) << '\n';
    cout << "A/B/C example operation counts: " << algorithmAWork(n) << ", "
              << algorithmBWork(n) << ", " << algorithmCWork(n) << '\n';
    cout << "O(n) operations: " << linearWork(n) << '\n';
    cout << "O(n) traversal operations: " << traversalWork(values) << '\n';
    cout << "Nested-loop iterations: " << nestedLoopWork(n) << '\n';
    cout << "O(n^2) operations: " << quadraticWork(n) << '\n';
    cout << "O(n^2) bubble-sort assignments: "
              << bubbleSortAssignments(values) << '\n';
    if (n <= 30) {
        cout << "O(2^n) loop operations: " << exponentialLoopWork(n) << '\n';
    } else {
        cout << "O(2^n) loop operations skipped for n > 30.\n";
    }
    cout << "O(log n) loop steps: " << logarithmicLoopWork(n) << '\n';
    cout << "O(log n) recursive steps: " << logarithmicRecursiveWork(n) << '\n';

    if (n <= 20) {
        cout << "O(2^n) recursive work: " << exponentialRecursiveWork(n) << '\n';
    } else {
        cout << "O(2^n) recursive work skipped for n > 20.\n";
    }
    if (n <= 1024) {
        cout << "O(n log n) recurrence work: "
                  << linearithmicRecursiveWork(n) << '\n';
    }
    if (n <= 10) {
        cout << "O(n!) recursive branch count: " << factorialBranchCount(n) << '\n';
    } else {
        cout << "O(n!) recursive branch count skipped for n > 10.\n";
    }
}
