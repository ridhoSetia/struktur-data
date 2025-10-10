#include <iostream>
using namespace std;
// Struktur Node untuk Binary Tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree
Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

/**
 * @brief Fungsi untuk melakukan pre-order traversal pada tree.
 * @param root Pointer ke node root dari tree.
 * @logic
 * 1. Jika node saat ini adalah nullptr, kembalikan (base case).
 * 2. Cetak data node saat ini.
 * 3. Rekursif ke subtree kiri.
 * 4. Rekursif ke subtree kanan.
 */

void preOrderTraversal(Node *root)
{
    // --- LENGKAPI KODE DI SINI ---
    if (root == nullptr)
        return;

    // Root > Kiri > Kanan

    // kunjungi dan tampilin node root nya
    cout << root->data << "->";
    // Rekursif buat kunjungi semua node di subtree kiri
    preOrderTraversal(root->left);
    // Rekursif buat kunjungi semua node di subtree kanan
    preOrderTraversal(root->right);
    // -----------------------------
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Pre-order traversal dari tree adalah: \n";
    preOrderTraversal(root); // Harusnya output: 50 30 20 40 70 60 80
    cout << endl;
    return 0;
}
