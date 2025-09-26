#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void transversal(Node *head)
{
    if (head == nullptr)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void tambahDiAkhir(Node *&head, int dataBaru)
{
    Node *newNode = new Node(); // Buat node baru
    newNode->data = dataBaru;
    newNode->next = nullptr;

    // Jika daftar masih kosong (head masih null), node baru menjadi head
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    // Jika daftar tidak kosong, telusuri hingga simpul terakhir
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    // Tambahkan node baru di akhir
    current->next = newNode;
}

int main()
{
    int b = 7;
    int *a = &b;
    cout << a << endl;

    b = 8;
    cout << *a << endl;

    Node *head = nullptr;

    cout << "Kondisi Awal:" << endl;
    transversal(head);

    cout << "\nMenambahkan beberapa elemen..." << endl;
    tambahDiAkhir(head, 10);
    tambahDiAkhir(head, 20);
    tambahDiAkhir(head, 30);

    cout << "\nKondisi Setelah Ditambah:" << endl;
    transversal(head);

    return 0;
}