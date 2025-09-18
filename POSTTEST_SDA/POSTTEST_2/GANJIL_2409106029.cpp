#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct Data
{
    int sid;
    string namaItem;
    int jumlah;
    string tipe;
};

struct Node
{
    Data data;
    Node *next;
};

// identitas global
struct Identitas
{
    string nama;
    long long nim;
};

Identitas identitas; // untuk menyimpan nama & NIM

// Prototipe
void menuUtama(Node *&head, int &jumlahRoster);
void buatAwal(Node *&head, int &jumlahRoster);
void tambahDepan(Node *&head, int &jumlahRoster);
void tambahBelakang(Node *&head, int &jumlahRoster);
void tambahPosisi(Node *&head, int &jumlahRoster);
void baca(Node *head);
void hapus(Node *&head, int &jumlahRoster);
void hapusDepan(Node *&head, int &jumlahRoster);
void hapusBelakang(Node *&head, int &jumlahRoster);
void hapusPosisi(Node *&head, int &jumlahRoster);
void gunakanItem(Node *&head, int &jumlahRoster);
Data inputData();
void inputPilihan(string namaPilihan, const string array[], int panjang, string &data);
void errorInput(int &input);

int main()
{
    Node *head = nullptr;
    int jumlahRoster = 0;

    cout << "Masukkan Nama : ";
    getline(cin, identitas.nama);
    cout << "Masukkan NIM  : ";
    cin >> identitas.nim;

    // node awal identitas
    Node *nodeIdentitas = new Node;
    nodeIdentitas->data.sid = 0;
    nodeIdentitas->data.namaItem = "Identitas: " + identitas.nama;
    nodeIdentitas->data.jumlah = identitas.nim % 100; // jumlah = nim % 100
    nodeIdentitas->data.tipe = "NIM";
    nodeIdentitas->next = nullptr;

    head = nodeIdentitas;
    jumlahRoster++;

    menuUtama(head, jumlahRoster);

    return 0;
}

void menuUtama(Node *&head, int &jumlahRoster)
{
    bool loop = true;
    while (loop)
    {
        cout << "\n==================================\n";
        cout << " Game Inventory Management \n (" << identitas.nama << " - " << identitas.nim << ")\n";
        cout << "==================================\n";
        cout << "1. Tambah data\n";
        cout << "2. Hapus data\n";
        cout << "3. Gunakan item\n";
        cout << "4. Tampilkan data\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";

        int pilih;
        cin >> pilih;

        switch (pilih)
        {
        case 1: buatAwal(head, jumlahRoster); break;
        case 2: hapus(head, jumlahRoster); break;
        case 3: gunakanItem(head, jumlahRoster); break;
        case 4: baca(head); break;
        case 5: loop = false; break;
        default: cout << "Pilihan tidak valid!\n"; break;
        }
    }
}

void buatAwal(Node *&head, int &jumlahRoster)
{
    int pilih;
    cout << "\n1. Tambah di depan\n";
    cout << "2. Tambah di belakang\n";
    cout << "3. Tambah di posisi (berdasarkan NIM)\n";
    cout << "0. Kembali\n";
    cout << "Pilih: ";
    cin >> pilih;

    switch (pilih)
    {
    case 1: tambahDepan(head, jumlahRoster); break;
    case 2: tambahBelakang(head, jumlahRoster); break;
    case 3: tambahPosisi(head, jumlahRoster); break;
    case 0: return;
    default: cout << "Input salah!\n"; break;
    }
}

void tambahDepan(Node *&head, int &jumlahRoster)
{
    Node *baru = new Node;
    baru->data = inputData();
    baru->data.jumlah = identitas.nim % 100;
    baru->next = head;
    head = baru;
    jumlahRoster++;
}

void tambahBelakang(Node *&head, int &jumlahRoster)
{
    Node *baru = new Node;
    baru->data = inputData();
    baru->data.jumlah = identitas.nim % 100;
    baru->next = nullptr;

    if (head == nullptr)
        head = baru;
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = baru;
    }
    jumlahRoster++;
}

void tambahPosisi(Node *&head, int &jumlahRoster)
{
    int posisi = (identitas.nim % 10) + 1; // posisi berdasarkan digit terakhir NIM + 1

    if (posisi <= 1)
    {
        tambahDepan(head, jumlahRoster);
        return;
    }

    Node *baru = new Node;
    baru->data = inputData();
    baru->data.jumlah = identitas.nim % 100;

    Node *temp = head;
    for (int i = 1; i < posisi - 1 && temp->next != nullptr; i++)
        temp = temp->next;

    baru->next = temp->next;
    temp->next = baru;
    jumlahRoster++;
}

void baca(Node *head)
{
    if (head == nullptr)
    {
        cout << ">> LinkedList kosong! <<\n";
        return;
    }

    int no = 1;
    cout << "\n= Daftar Item =\n";
    while (head != nullptr)
    {
        cout << no++ << ". SID         : " << head->data.sid << endl;
        cout << "   Nama Item  : " << head->data.namaItem << endl;
        cout << "   Jumlah     : " << head->data.jumlah << endl;
        cout << "   Tipe       : " << head->data.tipe << endl;
        head = head->next;
    }
}

void hapus(Node *&head, int &jumlahRoster)
{
    int pilih;
    cout << "\n1. Hapus depan\n";
    cout << "2. Hapus belakang\n";
    cout << "3. Hapus posisi\n";
    cout << "0. Kembali\n";
    cout << "Pilih: ";
    cin >> pilih;

    switch (pilih)
    {
    case 1: hapusDepan(head, jumlahRoster); break;
    case 2: hapusBelakang(head, jumlahRoster); break;
    case 3: hapusPosisi(head, jumlahRoster); break;
    case 0: return;
    default: cout << "Input salah!\n"; break;
    }
}

void hapusDepan(Node *&head, int &jumlahRoster)
{
    if (head == nullptr) return;
    Node *hapus = head;
    head = head->next;
    delete hapus;
    jumlahRoster--;
}

void hapusBelakang(Node *&head, int &jumlahRoster)
{
    if (head == nullptr) return;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
    jumlahRoster--;
}

void hapusPosisi(Node *&head, int &jumlahRoster)
{
    int posisi;
    cout << "Hapus urutan ke: ";
    cin >> posisi;

    if (posisi <= 1) { hapusDepan(head, jumlahRoster); return; }

    Node *temp = head;
    for (int i = 1; i < posisi - 1 && temp->next != nullptr; i++)
        temp = temp->next;

    if (temp->next == nullptr) return;

    Node *hapus = temp->next;
    temp->next = hapus->next;
    delete hapus;
    jumlahRoster--;
}

void gunakanItem(Node *&head, int &jumlahRoster)
{
    string cari;
    cout << "Gunakan Item: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, cari);

    Node *temp = head, *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->data.namaItem == cari)
        {
            if (temp->data.jumlah > 0)
            {
                temp->data.jumlah--;
                cout << "Item " << cari << " digunakan! Sisa: " << temp->data.jumlah << endl;

                if (temp->data.jumlah == 0)
                {
                    cout << "Item habis, dihapus dari daftar.\n";
                    if (prev == nullptr) head = temp->next;
                    else prev->next = temp->next;
                    delete temp;
                    jumlahRoster--;
                }
            }
            else cout << "Item sudah habis!\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Item tidak ditemukan!\n";
}

Data inputData()
{
    Data d;
    cout << "\nMasukkan SID  : ";
    cin >> d.sid;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nama Item     : ";
    getline(cin, d.namaItem);

    const string tipe[] = {"Sword", "Potion", "Bow", "Axe", "Spear", "Dagger", "Staff",
                           "Shield", "Helmet", "Chestplate", "Boots", "Gloves",
                           "Elixir", "Food", "Herb", "Antidote", "Mana Crystal",
                           "Key", "Treasure Map", "Gemstone", "Coin"};
    inputPilihan("Tipe Item :", tipe, 21, d.tipe);

    return d;
}

void inputPilihan(string namaPilihan, const string array[], int panjang, string &data)
{
    int input = 1;
    cout << "\n" << namaPilihan << endl;
    for (int i = 0; i < panjang; i++)
        cout << "   " << i + 1 << ". " << array[i] << endl;

    do
    {
        cout << "Pilih (1-" << panjang << "): ";
        cin >> input;
        errorInput(input);
    } while (input <= 0 || input > panjang);

    data = array[input - 1];
}

void errorInput(int &input)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Mohon masukkan angka: ";
        cin >> input;
    }
}
