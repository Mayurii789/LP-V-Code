#include <omp.h>
#include <iostream>
#include <climits>

int main() {
    const int size = 200;
    int numbers[size];
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % size;
    }

    // Initialize the array with some values.
    // for (int i = 0; i < size; ++i) {
    //     numbers[i] = i + 1;
    // }

    int min_val = INT_MAX;
    int max_val = INT_MIN;
    int sum = 0;
    double avg = 0.0;

    #pragma omp parallel for reduction(min: min_val) reduction(max: max_val) reduction(+: sum)
    for (int i = 0; i < size; ++i) {
        min_val = std::min(min_val, numbers[i]);
        max_val = std::max(max_val, numbers[i]);
        sum += numbers[i];
    }

    avg = static_cast<double>(sum) / size;

    std::cout << "Min: " << min_val << "\n";
    std::cout << "Max: " << max_val << "\n";
    std::cout << "Sum: " << sum << "\n";
    std::cout << "Average: " << avg << "\n";

    return 0;
}


/*
commanfd to compile and run the code:
g++ -fopenmp Parallel_BFS_DFS.cpp -o Parallel_BFS_DFS
./Parallel_BFS_DFS
*/