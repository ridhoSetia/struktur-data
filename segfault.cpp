#include <iostream>

int main() {
    std::cout << "Memaksa akses alamat memori ilegal (0x0)...\n";
    int* invalid_ptr = nullptr;

    // Penulisan ke alamat 0x0 melanggar Limit Register MMU
    *invalid_ptr = 9999;

    return 0;
}
