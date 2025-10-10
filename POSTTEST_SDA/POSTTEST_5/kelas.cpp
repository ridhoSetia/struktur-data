#include <iostream>
#include <queue> // Hanya butuh queue untuk BFS, stack tidak dipakai

using namespace std;

// Struktur Node untuk Binary Tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor untuk inisialisasi node baru
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// --- Operasi Binary Search Tree (BST) ---

// Fungsi untuk menambahkan node baru ke dalam BST
Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val); // Jika tree kosong, node baru jadi root
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val); // Jika nilai lebih kecil, ke sub-tree kiri
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val); // Jika nilai lebih besar, ke sub-tree kanan
    }
    return root;
}

// Fungsi untuk mencari node dalam BST
Node *search(Node *root, int val)
{
    // Jika root null atau data ditemukan, kembalikan root
    if (root == nullptr || root->data == val)
    {
        return root;
    }
    // Jika nilai yang dicari lebih kecil, cari di sub-tree kiri
    if (val < root->data)
    {
        return search(root->left, val);
    }
    // Jika lebih besar, cari di sub-tree kanan
    return search(root->right, val);
}

// Fungsi bantuan untuk mencari node dengan nilai terkecil
Node *findMinValueNode(Node *node)
{
    Node *current = node;
    // Terus ke kiri sampai menemukan node paling kiri (nilai terkecil)
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

// Fungsi untuk menghapus node dari BST
Node *deleteNode(Node *root, int val)
{
    if (root == nullptr)
    {
        return root; // Jika tree kosong, tidak ada yg dihapus
    }

    // Cari node yang akan dihapus
    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else // Node ditemukan
    {
        // Kasus 1 & 2: Node punya 0 atau 1 anak
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Kasus 3: Node punya 2 anak
        // Cari penerus in-order (nilai terkecil di sub-tree kanan)
        Node *temp = findMinValueNode(root->right);
        // Salin data penerus ke node ini
        root->data = temp->data;
        // Hapus node penerus in-order dari sub-tree kanan
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// --- Tree Traversal ---

// In-Order Traversal: Kiri > Akar > Kanan
void inorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left); // kunjungi subTree kiri
    cout << root->data << " ";    // kunjungi node akar
    inorderTraversal(root->right);// kunjungi subTree kanan
}

// Pre-Order Traversal: Akar > Kiri > Kanan
void preorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Post-Order Traversal: Kiri > Kanan > Akar
void postorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Level-Order Traversal (BFS) menggunakan Queue
void bfs(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}

// --- Fungsi Utama untuk Pengujian ---
int main()
{
    Node *root = nullptr; // Awalnya, tree kosong

    // 1. Membangun BST
    cout << "Membangun BST dengan memasukkan nilai: 50, 30, 70, 20, 40, 60, 80 " << endl;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    cout << "BST berhasil dibangun." << endl
         << endl;

    // 2. Traversal
    cout << "Traversal In-Order (Kiri > Akar > Kanan): ";
    inorderTraversal(root);
    cout << endl;
    cout << "Traversal Pre-Order (Akar > Kiri > Kanan): ";
    preorderTraversal(root);
    cout << endl;
    cout << "Traversal Post-Order (Kiri > Kanan > Akar): ";
    postorderTraversal(root);
    cout << endl;
    cout << "Traversal Level-Order (BFS): ";
    bfs(root);
    cout << endl
         << endl;

    // 3. Pencarian Node
    int val_to_search = 40;
    Node *search_result = search(root, val_to_search);
    // PERBAIKAN: Cek jika hasil pencarian BUKAN nullptr (!=)
    if (search_result != nullptr)
    {
        cout << "Nilai " << val_to_search << " ditemukan di Tree." << endl;
    }
    else
    {
        cout << "Nilai " << val_to_search << " tidak ditemukan di Tree." << endl;
    }
    val_to_search = 99;
    search_result = search(root, val_to_search);
    // PERBAIKAN: Cek jika hasil pencarian BUKAN nullptr (!=)
    if (search_result != nullptr)
    {
        cout << "Nilai " << val_to_search << " ditemukan di Tree." << endl
             << endl;
    }
    else
    {
        cout << "Nilai " << val_to_search << " tidak ditemukan di Tree." << endl
             << endl;
    }

    // 4. Penghapusan Node
    cout << "Menghapus node 20 (node daun)." << endl;
    root = deleteNode(root, 20);
    cout << "In-Order Traversal setelah menghapus 20: ";
    inorderTraversal(root);
    cout << endl
         << endl;

    cout << "Menghapus node 30 (node dengan satu anak)." << endl;
    root = deleteNode(root, 30);
    cout << "In-Order Traversal setelah menghapus 30: ";
    inorderTraversal(root);
    cout << endl
         << endl;

    cout << "Menghapus node 50 (root dengan dua anak)." << endl;
    root = deleteNode(root, 50);
    cout << "In-Order Traversal setelah menghapus 50: ";
    inorderTraversal(root);
    cout << endl
         << endl;
         
    return 0;
}