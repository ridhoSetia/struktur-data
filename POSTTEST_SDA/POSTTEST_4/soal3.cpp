#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string document;
    Node *next;
};

void enqueue(Node *&front, Node *&rear, string document)
{
    Node *newNode = new Node{document, nullptr};

    // --- LENGKAPI DI SINI ---
    // 1. Jika queue kosong (front == nullptr), set front dan rear ke newNode
    if (front == nullptr)
    {
        front = newNode;
        rear = newNode;
    }
    // 2. Jika tidak kosong, sambungkan rear->next ke newNode, lalu update rear
    // --- LENGKAPI DI SINI ---
    else
    {
        rear->next = newNode;
    }
    rear = newNode;
}

string dequeue(Node *&front, Node *&rear)
{
    if (front == nullptr)
        return ""; // Queue kosong

    // --- LENGKAPI DI SINI ---
    // 1. Simpan data dari front node
    Node *temp = front;
    // 2. Geser front ke front->next
    front = front->next;
    // 3. Jika front menjadi nullptr, set rear juga ke nullptr
    if (front == nullptr)
    {
        rear = nullptr;
    }

    // 4. Delete node lama dan return data
    // --- LENGKAPI DI SINI ---
    delete temp;

    return front->document; // Placeholder
}

void processAllDocuments(Node *&front, Node *&rear)
{
    // --- LENGKAPI DI SINI ---
    // Loop hingga queue kosong, dequeue dan print setiap dokumen
    // Format: "Memproses: [nama_dokumen]"
    // --- LENGKAPI DI SINI ---
    if (!front)
    {
        cout << "Antrian Kosong\n";
        return;
    }
    while (front)
    {
        cout << "Memproses: " << front->document << endl;
        front = front->next;
        if (!front)
        {
            cout << "Antrian Kosong\n";
            return;
        }
    }
}

int main()
{
    Node *front = nullptr;
    Node *rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}