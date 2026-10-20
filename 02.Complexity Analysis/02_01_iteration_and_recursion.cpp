#include <iostream>
#include <stack>
#include <string>

using namespace std;

int sumWithForLoop(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int sumWithWhileLoop(int n) {
    int sum = 0;
    int i = 1;
    while (i <= n) {
        sum += i;
        ++i;
    }
    return sum;
}

int sumWithMultipleUpdates(int n) {
    int sum = 0;
    int i = 1;
    while (i <= n) {
        sum += i;
        ++i;
        i *= 2;
    }
    return sum;
}

string listCoordinatePairs(int n) {
    string result;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            result += "(" + to_string(i) + ", " + to_string(j) + ") ";
        }
    }
    return result;
}

int sumRecursively(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumRecursively(n - 1);
}

int sumTailRecursively(int n, int partialSum = 0) {
    if (n == 0) {
        return partialSum;
    }
    return sumTailRecursively(n - 1, partialSum + n);
}

int fibonacciRecursively(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursively(n - 1) + fibonacciRecursively(n - 2);
}

int sumUsingExplicitStack(int n) {
    stack<int> pending;
    for (int value = n; value > 0; --value) {
        pending.push(value);
    }

    int sum = 0;
    while (!pending.empty()) {
        sum += pending.top();
        pending.pop();
    }
    return sum;
}

int main() {
    int n = 0;
    if (!(cin >> n) || n < 0) {
        cerr << "Enter a non-negative integer.\n";
        return 1;
    }
    if (n > 1000) {
        cerr << "Use n <= 1000 to keep recursion depth safe.\n";
        return 1;
    }

    cout << "For-loop sum: " << sumWithForLoop(n) << '\n';
    cout << "While-loop sum: " << sumWithWhileLoop(n) << '\n';
    cout << "While loop with two updates: " << sumWithMultipleUpdates(n) << '\n';
    cout << "Recursive sum: " << sumRecursively(n) << '\n';
    cout << "Tail-recursive sum: " << sumTailRecursively(n) << '\n';
    cout << "Explicit-stack sum: " << sumUsingExplicitStack(n) << '\n';
    cout << "The coordinate-pair loop performs n^2 iterations.\n";
    if (n <= 20) {
        cout << "Naive recursive Fibonacci F(" << n << "): "
                  << fibonacciRecursively(n) << '\n';
    } else {
        cout << "Naive recursive Fibonacci omitted for n > 20.\n";
    }
}
