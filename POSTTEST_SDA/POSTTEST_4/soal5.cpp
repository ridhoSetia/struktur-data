#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

/*
 * Fungsi ini menerima referensi ke pointer head dan tail.
 * Pointer head dan tail akan di-update setelah penukaran.
 */
void exchangeHeadAndTail(Node *&head_ref) {
    // Hanya berjalan jika ada 2 node atau lebih
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;
    Node* tail = head_ref->prev;  // Tail adalah prev dari head

    // Hal yang perlu dilakukan:
    // Buat kondisi jika hanya 2 node, cukup swap head_ref
    // Simpan neighbor ( yaitu head_next dan tail_prev)
    // Update koneksi: tail_prev <-> tail <-> head_next
    // Update koneksi: head_next <- ... -> tail_prev <-> head <-> tail_prev
    // terakhir Update head_ref

    // kondisi bisa kalian sesuaikan sendiri tapi usahakan outputnya sama
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main()
{
    Node *head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    // Expected output: 5 2 3 4 1
    printList(head);

    return 0;
}