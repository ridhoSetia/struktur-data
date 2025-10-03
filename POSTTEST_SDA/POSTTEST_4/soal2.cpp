#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

// Anda bisa menggunakan fungsi push dan pop dari soal sebelumnya.
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

bool areBracketsBalanced(string expr)
{
    Node *stackTop = nullptr;

    // --- LENGKAPI DI SINI ---
    // 1. Loop setiap karakter dalam `expr`.
    for (char c : expr)
    {
        // cek dulu yang dihasilkan oleh satu_s dengan cara
        // melihat apakah benar yang keluar itu setiap char dari string s
        cout << c << ", ";
    }
    // 2. Jika karakter adalah kurung buka '(', '{', '[', push ke stack.
    for (char c : expr)
    {
        if (c == '(')
        {
            push(stackTop, c);
        }
        else if (c == '{')
        {
            push(stackTop, c);
        }
        else if (c == '[')
        {
            push(stackTop, c);
        }
        else
        {
            break;
        }

        // buat debugging, jadi dipake buat ngecek sudah benar atau belum data yang di push
        // cout << "top = " << stackTop->data << endl;
    }
    // 3. Jika karakter adalah kurung tutup ')', '}', ']', cek:
    //    a. Apakah stack kosong? Jika ya, return false.
    //    b. Pop stack, lalu cek apakah kurung tutup cocok dengan kurung buka. Jika tidak, return false.
    for (char c : expr)
    {
        // buat string untuk menampung pasangan dari kurung,
        // nantinya akan dicek apakah kurung berpasangan
        string pasangan_kurung = "";
        if (c == ')')
        {
            if (stackTop == nullptr)
            {
                cout << "Stack underflow\n";
                return false;
            }

            // tambah pasangan_kurang dengan 
            // pembuka kurung paling atas dengan kondisi tutup karang saat ini 
            pasangan_kurung = pasangan_kurung + pop(stackTop) + c;
            // kalau gak sama, hentikan dengan mengembalikan nilai yang salah/false
            if (pasangan_kurung != "()")
            {
                return false;
            }
            // balikkan nilai benar/true dan keluarkan output seimbang jika benar
            else
            {
                return true;
            }
        }
        else if (c == '}')
        {
            if (stackTop == nullptr)
            {
                cout << "Stack underflow\n";
                return false;
            }

            pasangan_kurung = pasangan_kurung + pop(stackTop) + c;
            if (pasangan_kurung != "{}")
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (c == ']')
        {
            if (stackTop == nullptr)
            {
                cout << "Stack underflow\n";
                return false;
            }

            pasangan_kurung = pasangan_kurung + pop(stackTop) + c;
            if (pasangan_kurung != "[]")
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    // 4. Setelah loop selesai, jika stack kosong, return true. Jika tidak, return false.
    // --- LENGKAPI DI SINI ---
    if (!stackTop)
    {
        cout << "Stack kosong\n";
        return true;
    }

    return false;
}

int main()
{
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Seimbang
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}
