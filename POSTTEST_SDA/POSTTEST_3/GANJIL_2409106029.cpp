#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>

using namespace std;

// -- 1. MODEL DATA & STRUKTUR DATA --
struct DataItem
{
    int id;
    string namaItem;
    int jumlah;
    string tipe;
};

struct Node
{
    DataItem item;
    Node *next;
    Node *prev;
};

struct ItemList
{
    Node *head = nullptr;
    Node *tail = nullptr;
};

struct Identitas
{
    string nama;
    long long nim;
};

enum Halaman
{
    UTAMA,
    MENU_TAMBAH,
    MENU_HAPUS,
    GUNAKAN_ITEM_FORM,
    TAMBAH_DEPAN_FORM,
    TAMBAH_BELAKANG_FORM,
    TAMBAH_POSISI_FORM,
    HAPUS_POSISI_FORM,
    CARI_ITEM_FORM,
    DETAIL_ITEM,
    LIHAT_TERBALIK
};

// -- 2. STATE APLIKASI --
struct AppState
{
    Halaman halamanAktif = UTAMA;
    ItemList daftarItem;
    Identitas identitas;
    string pesanInfo = "";
    Node* itemDipilih = nullptr; // Menyimpan pointer ke item yang dicari/dipilih
};

// -- 3. KOMPONEN VIEW --
namespace View
{
    void clearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void renderHeader(const AppState &state)
    {
        cout << "========================================\n";
        cout << "      Game Inventory Management \n";
        if (!state.identitas.nama.empty())
        {
            cout << "      (" << state.identitas.nama << " - " << state.identitas.nim << ")\n";
        }
        cout << "========================================\n\n";
    }

    void renderInfoMessage(const AppState &state)
    {
        if (!state.pesanInfo.empty())
        {
            cout << "[INFO] " << state.pesanInfo << "\n\n";
        }
    }

    void renderTabelHeader()
    {
        cout << "--- Daftar Item ---\n";
        cout << left;
        cout << setw(5) << "No." << setw(8) << "ID" << setw(25) << "Nama Item"
             << setw(10) << "Jumlah" << setw(20) << "Tipe" << "\n";
        cout << "-----------------------------------------------------------------\n";
    }

    void renderTabelBody(const AppState &state)
    {
        if (state.daftarItem.head == nullptr)
        {
            cout << "Inventaris kosong.\n";
        }
        else
        {
            Node *current = state.daftarItem.head;
            int no = 1;
            while (current != nullptr)
            {
                cout << setw(5) << no++
                     << setw(8) << current->item.id
                     << setw(25) << current->item.namaItem
                     << setw(10) << current->item.jumlah
                     << setw(20) << current->item.tipe << "\n";
                current = current->next;
            }
        }
    }

    // FUNGSI Menampilkan tabel dari belakang (tail ke head)
    void renderTabelBodyReverse(const AppState &state)
    {
        if (state.daftarItem.tail == nullptr)
        {
            cout << "Inventaris kosong.\n";
        }
        else
        {
            Node *current = state.daftarItem.tail;
            int no = 1;
            while (current != nullptr)
            {
                cout << setw(5) << no++
                     << setw(8) << current->item.id
                     << setw(25) << current->item.namaItem
                     << setw(10) << current->item.jumlah
                     << setw(20) << current->item.tipe << "\n";
                current = current->prev; // Traversal menggunakan pointer 'prev'
            }
        }
         cout << "\n[INFO] Menampilkan item dari yang terbaru (tail) ke terlama (head)." << endl;
    }

    void renderMenuUtama()
    {
        cout << "\n--- Menu Utama ---\n";
        cout << "[1] Tambah Item\n";
        cout << "[2] Hapus Item\n";
        cout << "[3] Gunakan Item\n";
        cout << "[4] Cari Detail Item\n";
        cout << "[5] Tampilkan Item Terbalik (Traversal)\n";
        cout << "[0] Keluar\n";
        cout << "Pilihan: ";
    }
    
    void renderMenuTambah() {
        cout << "\n--- Menu Tambah Item ---\n";
        cout << "[1] Tambah di Depan\n";
        cout << "[2] Tambah di Belakang\n";
        cout << "[3] Tambah di Posisi (NIM)\n";
        cout << "[0] Kembali ke Menu Utama\n";
        cout << "Pilihan: ";
    }
    
    void renderMenuHapus() {
        cout << "\n--- Menu Hapus Item ---\n";
        cout << "[1] Hapus dari Depan\n";
        cout << "[2] Hapus dari Belakang\n";
        cout << "[3] Hapus dari Posisi Tertentu\n";
        cout << "[0] Kembali ke Menu Utama\n";
        cout << "Pilihan: ";
    }

    void renderFormGunakanItem(){
        cout << "Masukkan Nama Item yang akan digunakan: ";
    }

    // Fungsi Menampilkan form pencarian
    void renderFormCariItem() {
        cout << "--- Cari Item ---\n";
        cout << "Masukkan ID atau Nama Item yang dicari: ";
    }
    
    // Fungsi Menampilkan detail item yang ditemukan
    void renderDetailItem(const AppState& state) {
        if (state.itemDipilih == nullptr) {
            cout << "Item tidak valid untuk ditampilkan.\n";
        } else {
            DataItem& item = state.itemDipilih->item;
            cout << "--- Detail Item: " << item.namaItem << " ---\n";
            cout << "ID       : " << item.id << endl;
            cout << "Nama     : " << item.namaItem << endl;
            cout << "Jumlah   : " << item.jumlah << endl;
            cout << "Tipe     : " << item.tipe << endl;
            cout << "---------------------------------\n";
        }
        cout << "\n[0] Kembali ke Menu Utama\n";
        cout << "Pilihan: ";
    }


    void render(const AppState &state)
    {
        clearScreen();
        renderHeader(state);
        renderInfoMessage(state);

        switch (state.halamanAktif)
        {
        case UTAMA:
            renderTabelHeader();
            renderTabelBody(state);
            renderMenuUtama();
            break;
        case MENU_TAMBAH:
            renderTabelHeader();
            renderTabelBody(state);
            renderMenuTambah();
            break;
        case MENU_HAPUS:
            renderTabelHeader();
            renderTabelBody(state);
            renderMenuHapus();
            break;
        case GUNAKAN_ITEM_FORM:
            renderTabelHeader();
            renderTabelBody(state);
            renderFormGunakanItem();
            break;
        case CARI_ITEM_FORM:
            renderTabelHeader();
            renderTabelBody(state);
            renderFormCariItem();
            break;
        case DETAIL_ITEM:
            renderDetailItem(state);
            break;
        case LIHAT_TERBALIK:
            renderTabelHeader();
            renderTabelBodyReverse(state);
            renderMenuUtama();
            break;
        case TAMBAH_DEPAN_FORM:
        case TAMBAH_BELAKANG_FORM:
        case TAMBAH_POSISI_FORM:
        case HAPUS_POSISI_FORM:
             break;
        }
    }
} // namespace View

// -- 4. KOMPONEN USE CASE --
namespace UseCase
{
    void handleCinError()
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    string pilihTipeItem() {
        const vector<string> tipe = {"Sword", "Potion", "Bow", "Axe", "Spear", "Dagger", "Staff",
                                 "Shield", "Helmet", "Chestplate", "Boots", "Gloves",
                                 "Elixir", "Food", "Herb", "Antidote", "Mana Crystal",
                                 "Key", "Treasure Map", "Gemstone", "Coin"};
        
        cout << "\nPilih Tipe Item:\n";
        for (size_t i = 0; i < tipe.size(); ++i) {
            cout << "  [" << i + 1 << "] " << tipe[i] << endl;
        }

        int pilihan = 0;
        do {
            cout << "Pilihan (1-" << tipe.size() << "): ";
            cin >> pilihan;
            handleCinError();
        } while (pilihan <= 0 || pilihan > tipe.size());

        return tipe[pilihan - 1];
    }
    DataItem inputDataItem()
    {
        DataItem d;
        cout << "\n--- Form Tambah Item ---\n";
        cout << "Masukkan ID Item: ";
        cin >> d.id;
        handleCinError();
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nama Item: ";
        getline(cin, d.namaItem);

        d.tipe = pilihTipeItem();

        return d;
    }
    void tambahDepan(AppState &state)
    {
        DataItem itemBaru = inputDataItem();
        itemBaru.jumlah = state.identitas.nim % 100;

        Node* newNode = new Node{itemBaru, state.daftarItem.head, nullptr};
        
        if (state.daftarItem.head == nullptr) {
            state.daftarItem.head = state.daftarItem.tail = newNode;
        } else {
            state.daftarItem.head->prev = newNode;
            state.daftarItem.head = newNode;
        }
        state.pesanInfo = "Item '" + itemBaru.namaItem + "' berhasil ditambahkan di depan.";
        state.halamanAktif = UTAMA;
    }
    void tambahBelakang(AppState &state)
    {
        DataItem itemBaru = inputDataItem();
        itemBaru.jumlah = state.identitas.nim % 100;

        Node* newNode = new Node{itemBaru, nullptr, state.daftarItem.tail};

        if (state.daftarItem.head == nullptr) {
            state.daftarItem.head = state.daftarItem.tail = newNode;
        } else {
            state.daftarItem.tail->next = newNode;
            state.daftarItem.tail = newNode;
        }
        state.pesanInfo = "Item '" + itemBaru.namaItem + "' berhasil ditambahkan di belakang.";
        state.halamanAktif = UTAMA;
    }
    void tambahPosisi(AppState &state) {
        int posisi = (state.identitas.nim % 10) + 1;
        
        if (posisi <= 1) {
            tambahDepan(state);
            state.pesanInfo += " (Berdasarkan NIM, posisi <= 1)";
            return;
        }

        Node* current = state.daftarItem.head;
        int i = 1;
        while(i < posisi - 1 && current != nullptr && current != state.daftarItem.tail) {
            current = current->next;
            i++;
        }

        if(current == nullptr || current == state.daftarItem.tail) {
            tambahBelakang(state);
            state.pesanInfo += " (Berdasarkan NIM, posisi melebihi batas, ditambah di akhir)";
        } else {
            DataItem itemBaru = inputDataItem();
            itemBaru.jumlah = state.identitas.nim % 100;
            Node* newNode = new Node{itemBaru, current->next, current};

            if(current->next != nullptr){
                current->next->prev = newNode;
            }
            current->next = newNode;

            state.pesanInfo = "Item '" + itemBaru.namaItem + "' berhasil ditambahkan pada posisi " + to_string(posisi) + " (NIM).";
        }
        state.halamanAktif = UTAMA;
    }
    void hapusDepan(AppState &state) {
        if(state.daftarItem.head == nullptr) {
            state.pesanInfo = "Gagal! Inventaris sudah kosong.";
        } else {
            Node* temp = state.daftarItem.head;
            state.daftarItem.head = state.daftarItem.head->next;
            
            if (state.daftarItem.head != nullptr) {
                state.daftarItem.head->prev = nullptr;
            } else { 
                state.daftarItem.tail = nullptr;
            }
            state.pesanInfo = "Item '" + temp->item.namaItem + "' berhasil dihapus dari depan.";
            delete temp;
        }
        state.halamanAktif = UTAMA;
    }
    void hapusBelakang(AppState &state) {
        if(state.daftarItem.head == nullptr) {
            state.pesanInfo = "Gagal! Inventaris sudah kosong.";
        } else {
            Node* temp = state.daftarItem.tail;
            state.daftarItem.tail = state.daftarItem.tail->prev;

            if (state.daftarItem.tail != nullptr) {
                state.daftarItem.tail->next = nullptr;
            } else {
                state.daftarItem.head = nullptr;
            }
            state.pesanInfo = "Item '" + temp->item.namaItem + "' berhasil dihapus dari belakang.";
            delete temp;
        }
        state.halamanAktif = UTAMA;
    }
    void hapusPosisi(AppState &state, int posisi) {
        if(posisi <= 0) {
            state.pesanInfo = "Posisi tidak valid!";
            state.halamanAktif = MENU_HAPUS;
            return;
        }
        if(posisi == 1) {
            hapusDepan(state);
            return;
        }
        
        Node* current = state.daftarItem.head;
        for(int i = 1; i < posisi && current != nullptr; i++) {
            current = current->next;
        }

        if(current == nullptr) {
            state.pesanInfo = "Gagal! Posisi " + to_string(posisi) + " tidak ditemukan.";
        } else {
            if(current->prev != nullptr) current->prev->next = current->next;
            if(current->next != nullptr) current->next->prev = current->prev;

            if(current == state.daftarItem.tail) state.daftarItem.tail = current->prev;

            state.pesanInfo = "Item '" + current->item.namaItem + "' pada posisi " + to_string(posisi) + " berhasil dihapus.";
            delete current;
        }
        state.halamanAktif = UTAMA;
    }
    void gunakanItem(AppState &state, const string& namaItem) {
        Node *current = state.daftarItem.head;
        while(current != nullptr) {
            if(current->item.namaItem == namaItem) {
                if(current->item.jumlah > 0) {
                    current->item.jumlah--;
                    state.pesanInfo = "Item '" + namaItem + "' digunakan! Sisa: " + to_string(current->item.jumlah);
                    if(current->item.jumlah == 0) {
                        if(current->prev) current->prev->next = current->next; else state.daftarItem.head = current->next;
                        if(current->next) current->next->prev = current->prev; else state.daftarItem.tail = current->prev;
                        delete current;
                        state.pesanInfo += ". Item habis dan dihapus dari inventaris.";
                    }
                } else {
                    state.pesanInfo = "Item '" + namaItem + "' sudah habis!";
                }
                state.halamanAktif = UTAMA;
                return;
            }
            current = current->next;
        }
        state.pesanInfo = "Item '" + namaItem + "' tidak ditemukan!";
        state.halamanAktif = UTAMA;
    }
    
    // Mencari item berdasarkan ID atau Nama
    void cariItem(AppState &state, const string& query) {
        state.itemDipilih = nullptr;
        Node* current = state.daftarItem.head;
        int searchId = -1;

        // Konversi query ke integer. Jika berhasil, cari berdasarkan ID.
        try {
            searchId = stoi(query);
            while(current != nullptr) {
                if(current->item.id == searchId) {
                    state.itemDipilih = current;
                    break;
                }
                current = current->next;
            }
        } 
        // Jika gagal (input bukan angka), cari berdasarkan Nama.
        catch (const invalid_argument& e) {
            while(current != nullptr) {
                if(current->item.namaItem == query) {
                    state.itemDipilih = current;
                    break;
                }
                current = current->next;
            }
        }

        if(state.itemDipilih != nullptr) {
            state.halamanAktif = DETAIL_ITEM;
            state.pesanInfo = "";
        } else {
            state.halamanAktif = UTAMA;
            state.pesanInfo = "Item dengan query '" + query + "' tidak ditemukan.";
        }
    }


    void prosesInput(AppState &state, const string &input)
    {
        state.pesanInfo = "";
        int pilihan = -1;
        try
        {
            pilihan = stoi(input);
        }
        catch (const invalid_argument &e)
        {
            state.pesanInfo = "Input harus berupa angka!";
            return;
        }
        
        if (state.halamanAktif == UTAMA || state.halamanAktif == LIHAT_TERBALIK) {
            state.halamanAktif = UTAMA;
            switch (pilihan) {
                case 1: state.halamanAktif = MENU_TAMBAH; break;
                case 2: state.halamanAktif = MENU_HAPUS; break;
                case 3: state.halamanAktif = GUNAKAN_ITEM_FORM; break;
                case 4: state.halamanAktif = CARI_ITEM_FORM; break;
                case 5: state.halamanAktif = LIHAT_TERBALIK; break;
                case 0: break;
                default: state.pesanInfo = "Pilihan tidak valid!"; break;
            }
        } else if (state.halamanAktif == MENU_TAMBAH) {
             switch (pilihan) {
                case 1: state.halamanAktif = TAMBAH_DEPAN_FORM; break;
                case 2: state.halamanAktif = TAMBAH_BELAKANG_FORM; break;
                case 3: state.halamanAktif = TAMBAH_POSISI_FORM; break;
                case 0: state.halamanAktif = UTAMA; break;
                default: state.pesanInfo = "Pilihan tidak valid!"; break;
            }
        } else if (state.halamanAktif == MENU_HAPUS) {
            switch (pilihan) {
                case 1: UseCase::hapusDepan(state); break;
                case 2: UseCase::hapusBelakang(state); break;
                case 3: state.halamanAktif = HAPUS_POSISI_FORM; break;
                case 0: state.halamanAktif = UTAMA; break;
                default: state.pesanInfo = "Pilihan tidak valid!"; break;
            }
        } else if (state.halamanAktif == DETAIL_ITEM) {
            if (pilihan == 0) {
                state.halamanAktif = UTAMA;
                state.itemDipilih = nullptr;
            } else {
                state.pesanInfo = "Pilihan tidak valid!";
            }
        }
    }
} // namespace UseCase

// -- 5. MAIN APPLICATION LOOP --
int main()
{
    AppState state;
    string input;

    cout << "Masukkan Nama : ";
    getline(cin, state.identitas.nama);
    cout << "Masukkan NIM  : ";
    cin >> state.identitas.nim;
    UseCase::handleCinError();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    DataItem itemIdentitas;
    itemIdentitas.id = 0;
    itemIdentitas.namaItem = "Identitas: " + state.identitas.nama;
    itemIdentitas.jumlah = state.identitas.nim % 100;
    itemIdentitas.tipe = "NIM";
    Node* nodeIdentitas = new Node{itemIdentitas, nullptr, nullptr};
    state.daftarItem.head = state.daftarItem.tail = nodeIdentitas;
    
    while (true)
    {
        View::render(state);

        if (state.halamanAktif == UTAMA || state.halamanAktif == MENU_TAMBAH || 
            state.halamanAktif == MENU_HAPUS || state.halamanAktif == DETAIL_ITEM ||
            state.halamanAktif == LIHAT_TERBALIK) {
            cin >> input;
            UseCase::handleCinError();
        }

        if (state.halamanAktif == UTAMA && input == "0") break;
        
        if (state.halamanAktif == UTAMA || state.halamanAktif == MENU_TAMBAH || 
            state.halamanAktif == MENU_HAPUS || state.halamanAktif == DETAIL_ITEM ||
            state.halamanAktif == LIHAT_TERBALIK) {
            UseCase::prosesInput(state, input);
        } else if (state.halamanAktif == GUNAKAN_ITEM_FORM) {
            string namaItem;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, namaItem);
            UseCase::gunakanItem(state, namaItem);
        } else if (state.halamanAktif == TAMBAH_DEPAN_FORM) {
            UseCase::tambahDepan(state);
        } else if (state.halamanAktif == TAMBAH_BELAKANG_FORM) {
            UseCase::tambahBelakang(state);
        } else if (state.halamanAktif == TAMBAH_POSISI_FORM) {
            UseCase::tambahPosisi(state);
        } else if (state.halamanAktif == HAPUS_POSISI_FORM) {
            int pos;
            cout << "Hapus item pada urutan ke: ";
            cin >> pos;
            UseCase::handleCinError();
            UseCase::hapusPosisi(state, pos);
        } else if (state.halamanAktif == CARI_ITEM_FORM) {
            cin >> input;
            UseCase::handleCinError();
            UseCase::cariItem(state, input);
        }
    }

    cout << "\nProgram selesai. Terima kasih!\n";
    return 0;
}