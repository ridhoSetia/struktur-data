#include <iostream>
#include <unistd.h>

int global_data = 100; // Data Segment

int main() {
    int stack_var = 50;          // Stack Segment
    int* heap_var = new int(200); // Heap Segment

    std::cout << "=================================================\n";
    std::cout << "  INSPEKSI MEMORI VIRTUAL PROSES (PID: " << getpid() << ")\n";
    std::cout << "=================================================\n";
    std::cout << "Alamat Virtual Data Segment  : " << &global_data << "\n";
    std::cout << "Alamat Virtual Heap Segment  : " << heap_var << "\n";
    std::cout << "Alamat Virtual Stack Segment : " << &stack_var << "\n";
    std::cout << "=================================================\n\n";

    std::cout << "Buka terminal baru dan ketik: pmap -x " << getpid() << "\n";
    std::cout << "Tekan ENTER untuk mengakhiri proses...";
    std::cin.get();

    delete heap_var;
    return 0;
}
