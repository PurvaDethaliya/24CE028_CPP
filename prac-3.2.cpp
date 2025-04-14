#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int recursive_sum(const vector<int>& arr, int index) {
    if (index == arr.size()) {
        return 0;
    }
    return arr[index] + recursive_sum(arr, index + 1);
}

int iterative_sum(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    auto start_recursive = chrono::high_resolution_clock::now();
    int recursive_result = recursive_sum(arr, 0);
    auto end_recursive = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_recursive = end_recursive - start_recursive;

    auto start_iterative = chrono::high_resolution_clock::now();
    int iterative_result = iterative_sum(arr);
    auto end_iterative = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_iterative = end_iterative - start_iterative;

    cout << "Recursive Sum: " << recursive_result << endl;
    cout << "Execution Time (Recursive): " << duration_recursive.count() << " seconds" << endl;

    cout << "Iterative Sum: " << iterative_result << endl;
    cout << "Execution Time (Iterative): " << duration_iterative.count() << " seconds" << endl;

    return 0;
}
