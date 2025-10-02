#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};
Lengkapi Fungsi berikut:

// Anda bisa menggunakan fungsi push dan pop dari soal sebelumnya.

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // --- LENGKAPI DI SINI ---
    // 1. Loop setiap karakter dalam `expr`.
    // 2. Jika karakter adalah kurung buka '(', '{', '[', push ke stack.
    // 3. Jika karakter adalah kurung tutup ')', '}', ']', cek:
    //    a. Apakah stack kosong? Jika ya, return false.
    //    b. Pop stack, lalu cek apakah kurung tutup cocok dengan kurung buka. Jika tidak, return false.
    // 4. Setelah loop selesai, jika stack kosong, return true. Jika tidak, return false.
    // --- LENGKAPI DI SINI ---

    return false; // Placeholder
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Seimbang
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}
