#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void addFirst(Node *&head, int data)
{
    Node *nodeBaru = new Node;
    nodeBaru->data = data;
    nodeBaru->next = head;
    head = nodeBaru;
}

void transversal(Node *head)
{
    if (head == nullptr)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void addMiddle(Node *&head, int databaru, int posisi)
{
    if (posisi <= 1)
    {
        addFirst(head, databaru);
        return;
    }

    Node *temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1)
    {
        temp = temp->next;
        hitung++;
    }
    if (temp == nullptr)
    {
        cout << ">> Posisi tidak boleh melebihi panjang list <<" <<

            endl;

        return;
    }
    else
    {
        cout << temp->data << endl;
        Node *nodeBaru = new Node;
        nodeBaru->data = databaru;
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
}

void addLast(Node *&head, int databaru)
{
    Node *nodeBaru = new Node;
    nodeBaru->data = databaru;
    nodeBaru->next = nullptr;

    // jika linked list kosong
    if (head == nullptr)
    {
        head = nodeBaru;
        return;
    }
    // jika tidak, traversal ke node terakhir
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

void deleteFirst(Node *&head)
{
    if (head == nullptr)
    {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

void editData(Node *&head, int posisi, int dataBaru)
{
    if (head == nullptr)
    {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }

    Node *temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi)
    {
        temp = temp->next;
        hitung++;
    }
    if (temp == nullptr)
    {
        cout << ">> Posisi tidak valid <<" << endl;
    }
    else
    {
        cout << "Data lama: " << temp->data << endl;
        temp->data = dataBaru;
        cout << "Data berhasil diubah menjadi: " << temp->data << endl;
    }
}

int main()
{
    Node *head = nullptr;
    addFirst(head, 10);
    addFirst(head, 20);
    addFirst(head, 30);
    addFirst(head, 40);
    addMiddle(head, 50, 2);
    editData(head, 3, 99);
    transversal(head);

    return 0;
}
