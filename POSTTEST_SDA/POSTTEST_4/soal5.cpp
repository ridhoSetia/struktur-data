#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

/*
 * Fungsi ini menerima referensi ke pointer head.
 * Pointer head akan di-update setelah penukaran.
 */
void exchangeHeadAndTail(Node *&head_ref)
{
    // Kasus 1: List kosong atau hanya punya 1 node, tidak ada yang perlu ditukar.
    if (head_ref == nullptr || head_ref->next == head_ref)
    {
        return;
    }

    Node *head = head_ref;
    Node *tail = head_ref->prev; // Dalam circular list, tail adalah node sebelum head.

    // Hal yang perlu dilakukan:
    // Buat kondisi jika hanya 2 node, cukup swap head_ref

    // Jadikan tail sebagai head baru. Pointernya sudah saling terhubung.
    if (head->next == tail)
    {
        head_ref = tail;
        return;
    }

    // Simpan neighbor ( yaitu head_next dan tail_prev)

    // Disini list punya 3 node atau lebih.
    // Simpan neighbore dari head dan tail agar tidak kehilangan jejak.
    Node *head_next = head->next; // Node setelah head (calon node ke-2)
    Node *tail_prev = tail->prev; // Node sebelum tail (calon node kedua dari akhir)
    
    // Update koneksi: tail_prev <-> tail <-> head_next

    // Mengupdate koneksi untuk neighbor.
    // tail_prev sekarang harus menunjuk ke head (yang akan jadi tail baru).
    tail_prev->next = head;
    // head_next sekarang harus menunjuk balik ke tail (yang akan jadi head baru).
    head_next->prev = tail;

    // Update koneksi: head_next <- ... -> tail_prev <-> head <-> tail_prev

    // Update koneksi untuk head dan tail itu sendiri.
    // Head lama(akan jadi tail baru) disambungkan.
    head->prev = tail_prev;
    head->next = tail; // Sambungan sirkular baru
    
    // Tail lama (akan jadi head baru) disambungkan.
    tail->prev = head; // Sambungan sirkular baru
    tail->next = head_next;

    // terakhir Update head_ref

    // Update head_ref untuk menunjuk ke head yang baru (yaitu tail lama).
    head_ref = tail;

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