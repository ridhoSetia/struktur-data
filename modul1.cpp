#include <iostream>

int main() {
    int n = 5;

    // best case
    // int A[5] = {5,4,3,2,1};

    // worst case
    int A[5] = {1,2,3,4,5};

    int max = A[0];

    for (int i = 1; i < n; i++) {
    std::cout << i << std::endl;
        if (A[i] > max) {
            max = A[i];
        }
    
    std::cout << "max = " << max << std::endl;
    return 0;
    }
}