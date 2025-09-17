#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Struct yang dibentuk sebagai data di node
struct Item
{
    int sid;
    string namaItem;
    int jumlah;
    string tipe;
};

// Node single linked list, hanya memiliki data dan pointer node next;
struct Node
{
    Item data;
    Node *next;
};

string nama;
long nim;

// Prototype
void Create(Node *&head, int &jumlahRoster, string menu);
void Read(Node *head);
void Delete(Node *&head, int &jumlahRoster, string menu);

// Prosedur Manipulasi Single Linked List
void CF(Node *&head, int &jumlahRoster);
void CL(Node *&head, int &jumlahRoster);
void CP(Node *&head, int &jumlahRoster);
void DF(Node *&head, int &jumlahRoster);
void DL(Node *&head, int &jumlahRoster);
void DP(Node *&head, int &jumlahRoster);

// Input dan Error handling
void inputPilihan(string namaPilihan, const string array[], int panjang, string &data);
Node inputData();
void errorInput(int &input);

int main()
{
    cout << "Nama mu: ";
    cin >> nama;
    cout << "NIM mu: ";
    cin >> nim;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // FIX: buang enter setelah input nim

    int jumlahRoster = 0, input;
    bool loop = true;
    Node *head = nullptr;

    string menuUtama = "\n == Game Inventory Management ==\n 1. Tambah Item Baru\n 2. Hapus Item\n 3.Gunakan Item\n4. Tampilkan Inventory 5. Keluar\n Masukan pilihan : ";
    string menuTambah = "\n == Tambah Data Baru ==\n 1. Tambah di awal\n 2. Tambah di akhir\n 3. Tambah urutan tertentu\n Masukan pilihan : ";
    string menuHapus = "\n == Hapus Data Roster Karakter ==\n 1. Hapus urutan pertama\n 2. Hapus urutan akhir\n 3. Hapus urutan tertentu\n Masukan pilihan : ";

    while (loop)
    {
        cout << menuUtama;
        cin >> input;
        switch (input)
        {
        case 1:
            Create(head, jumlahRoster, menuTambah);
            break;
        case 2:
            Delete(head, jumlahRoster, menuHapus);
            break;
        case 3:
            Use();
        case 4:
            Read(head);
            break;
        case 5:
            loop = false;
            break;
        default:
            cout << " \n Terjadi Kesalahan\n";
            break;
        }
    }

    return 0;
}

void Create(Node *&head, int &jumlahRoster, string menu)
{
    int input;
    bool loop = true;
    while (loop)
    {
        cout << menu;
        cin >> input;
        switch (input)
        {
        case 1: CF(head, jumlahRoster); loop = false; break;
        case 2: CL(head, jumlahRoster); loop = false; break;
        case 3: CP(head, jumlahRoster); loop = false; break;
        case 0: loop = false; break;
        default: cout << "Masukan antara 1-3 (0 untuk kembali)!"; break;
        }
    }
}

void CF(Node *&head, int &jumlahRoster)
{
    Node *nodeBaru = new Node;
    nodeBaru->data = inputData().data;
    nodeBaru->next = head;
    nodeBaru->data.jumlah = nim % 100;
    head = nodeBaru;
    jumlahRoster++;
}

void CL(Node *&head, int &jumlahRoster)
{
    if (head == nullptr)
    {
        CF(head, jumlahRoster);
        return;
    }
    Node *nodeBaru = new Node;
    nodeBaru->data = inputData().data;
    nodeBaru->next = nullptr;

    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = nodeBaru;
    jumlahRoster++;
}

void CP(Node *&head, int &jumlahRoster)
{
    int input;
    if (head == nullptr)
        cout << "Urutan ke (hanya 1) : ";
    else
        cout << "Urutan ke (1-" << jumlahRoster + 1 << ") : ";

    cin >> input;
    if (0 < input && input < jumlahRoster + 2)
    {
        if (input == 1) { CF(head, jumlahRoster); return; }
        else if (input == jumlahRoster + 1) { CL(head, jumlahRoster); return; }

        Node *nodeBaru = new Node;
        nodeBaru->data = inputData().data;
        Node *temp = head;
        for (int x = 0; x < input - 2; x++)
            temp = temp->next;
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
        nodeBaru->data.jumlah = (nim % 10)+1;
        jumlahRoster++;
    }
    else
        cout << "\n Tidak ada urutan " << input << "! \n";
}

void Read(Node *head)
{
    if (head == nullptr)
    {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    int no = 1;
    cout << " \n=Roster Karakter=\n";
    while (head != nullptr)
    {
        cout << no
             << ". SID         : " << head->data.sid << endl
             << "  Nama Item   : " << head->data.namaItem << endl
             << "  Jumlah Item : " << head->data.jumlah << endl
             << "  Tipe Item   : " << head->data.tipe << endl;
        no++;
        head = head->next;
    }
    cout << endl;
}

void Delete(Node *&head, int &jumlahRoster, string menu)
{
    if (head == nullptr)
    {
        cout << "\n >> LinkedList masih kosong << \n" << endl;
        return;
    }
    int input;
    bool loop = true;
    while (loop)
    {
        cout << menu;
        cin >> input;
        switch (input)
        {
        case 1: DF(head, jumlahRoster); loop = false; break;
        case 2: DL(head, jumlahRoster); loop = false; break;
        case 3: DP(head, jumlahRoster); loop = false; break;
        case 0: loop = false; break;
        default: cout << "Masukan antara 1-3 (0 untuk kembali)!"; break;
        }
    }
}

void DF(Node *&head, int &jumlahRoster)
{
    Node *cur = head;
    head = head->next;
    delete cur;
    jumlahRoster--;
    cout << "\n Telah dihapus! \n";
}

void DL(Node *&head, int &jumlahRoster)
{
    if (head->next == nullptr)
    {
        DF(head, jumlahRoster);
        return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    Node *cur = temp->next;
    temp->next = nullptr;
    delete cur;
    jumlahRoster--;
    cout << "\n Telah dihapus! \n";
}

void DP(Node *&head, int &jumlahRoster)
{
    int input;
    Read(head);
    cout << "Hapus urutan ke (1-" << jumlahRoster << ") : ";
    cin >> input;
    if (0 < input && input <= jumlahRoster)
    {
        if (input == 1) { DF(head, jumlahRoster); return; }
        else if (input == jumlahRoster) { DL(head, jumlahRoster); return; }

        Node *temp = head;
        for (int x = 1; x < input - 1; x++)
            temp = temp->next;
        Node *cur = temp->next;
        temp->next = cur->next;
        delete cur;
        jumlahRoster--;
        cout << "\n Telah dihapus! \n";
    }
    else
        cout << "\nTidak ada urutan " << input << "!\n";
}

void inputPilihan(string namaPilihan, const string array[], int panjang, string &data)
{
    int input = 1;
    cout << "\n  " << namaPilihan << endl;
    for (int i = 0; i < panjang; i++)
    {
        cout << "   " << i + 1 << ". " << array[i];
        if (i < panjang - 1) cout << endl;
    }

    do
    {
        cout << " \nMasukan angka 1-" << panjang << "! \n Input : ";
        cin >> input;
        errorInput(input);
    } while (input <= 0 || input > panjang);
    data = array[input - 1];
}

Node inputData()
{
    Node *dataBaru = new Node;
    cout << " \nTambah Data Karakter\n SID       : ";
    cin >> dataBaru->data.sid;
    errorInput(dataBaru->data.sid);

    cout << " Nama Item : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, dataBaru->data.namaItem);

    const string tipe[] = {"Sword", "Potion",
                           "Bow", "Axe", "Spear", "Dagger", "Staff",
                           "Shield", "Helmet", "Chestplate", "Boots", "Gloves",
                           "Elixir", "Food", "Herb", "Antidote", "Mana Crystal",
                           "Key", "Treasure Map", "Gemstone", "Coin"};
    inputPilihan("Tipe Item :", tipe, 21, dataBaru->data.tipe);

    cout << " \nBerhasil!\n ";
    return *dataBaru;
}

void errorInput(int &input)
{
    while (true)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Mohon masukan angka untuk input di atas!\n input :  ";
            cin >> input;
        }
        else break;
    }
}
