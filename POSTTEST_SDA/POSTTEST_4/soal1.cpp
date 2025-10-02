#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

// Fungsi Push dan Pop manual bisa dibuat di sini atau di dalam fungsi utama.
void push(Node *&top, char data)
{
    Node *newNode = new Node{data, top};
    newNode->next = top;
    top = newNode;
}

char pop(Node *&top)
{
    if (top == nullptr)
        return '\0'; // Return null character jika stack kosong
    Node *temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s)
{
    Node *stackTop = nullptr;
    string reversed = "";

    // --- LENGKAPI DI SINI ---
    // 1. Push setiap karakter dari string s ke dalam stack.
    for (char satu_s : s)
    {
        // cek dulu yang dihasilkan oleh satu_s dengan cara 
        // melihat apakah benar yang keluar itu setiap char dari string s
        // cout << satu_s << ", ";

        // karena benar maka kita push tiap isi dari satu_s ke dalam data
        push(stackTop, satu_s);
    }

    // 2. Pop setiap karakter dari stack dan tambahkan ke string `reversed`.
    // --- LENGKAPI DI SINI ---
    for (char satu_s : s)
    {
        // karena pop mengambil dari tumpukan paling atas dulu
        // yaitu dimulai dari a, t, dst, maka jika ingin melakukan reverse string
        // tambahkan tiap isi char yang di pop ke dalam variabel reversed
        reversed += pop(stackTop);
    }
    // hasil keseluruhan char yang ditambahkan satu persatu ke dalam reversed
    // akan di kembalikan nilainya agar dapat ditampilkan nantiny
    return reversed;
}

int main()
{
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; // Output: ataD rukurts
    return 0;
}