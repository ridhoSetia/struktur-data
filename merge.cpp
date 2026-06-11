#include <iostream>
#include <string>
using namespace std;

// Definisi Struct
struct Produk
{
    int id;
    string nama;
    int harga;
};

// Fungsi untuk menggabungkan dua bagian array Produk
void merge(Produk *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    cout << "n1: " << n1 << endl;
    int n2 = right - mid;
    cout << "n2: " << n1 << endl;

    cout << endl;

    // Membuat array sementara untuk menampung struct
    Produk *L = new Produk[n1];
    Produk *R = new Produk[n2];

    // Menyalin data ke array sementara menggunakan pointer akses
    for (int i = 0; i < n1; i++)
    {
        *(L + i) = *(arr + left + i); // L[i] = arr[left + i];
        // cout << (L + i) << endl;
    }

    for (int j = 0; j < n2; j++)
    {
        *(R + j) = *(arr + mid + 1 + j);
    }

    int i = 0, j = 0, k = left;

    // Proses penggabungan berdasarkan property 'harga'
    while (i < n1 && j < n2)
    {
        if ((L + i)->harga <= (R + j)->harga)
        {
            cout << "kiri: " << (L + i)->harga << " < " << "kanan: " << (R + j)->harga << endl;
            *(arr + k) = *(L + i); // Kalau harga di kiri lebih murah/sama, masukkan ke array utama
            cout << "harga di kiri lebih murah/sama: " << (arr + k)->harga << " Sekarang k:" << k << " diisi ini" << endl;
            i++;
        }
        else
        {
            cout << "kiri: " << (L + i)->harga << " > " << "kanan: " << (R + j)->harga << endl;
            *(arr + k) = *(R + j); // Kalau kanan lebih murah, masukkan yang kanan
            cout << "harga di kanan lebih murah: " << (arr + k)->harga << " Sekarang k:" << k << " diisi ini" << endl;
            j++;
        }
        k++;
        cout << endl;
    }

    cout << "i:" << i << endl;

    // Menyalin sisa elemen
    while (i < n1)
    {
        cout << "k:" << k << endl;
        cout << "(arr + k)->harga: " << (arr + k)->harga << endl;
        *(arr + k) = *(L + i); // Ambil isi data dari alamat memori L + i, lalu copy ke alamat memori arr + k
        cout << "(arr + k)->harga: " << (arr + k)->harga << endl;
        cout << endl;
        // L + i: Alamat elemen ke-i di array sementara kiri.
        // arr + k: Alamat elemen ke-k di array asli/utama.

        // karena kita memindahkan sebuah Struct maka operasi "=" disini akan menyalin isi dari struct sekaligus
        // lebih efisien dari pada kita salin satu persatu arr[k].id = L[i].id; arr[k].nama; dst

        i++;
        k++;
    }
    while (j < n2)
    {
        cout << "k:" << k << endl;
        cout << "(arr + k)->harga: " << (arr + k)->harga << endl;
        *(arr + k) = *(R + j);
        cout << "(arr + k)->harga: " << (arr + k)->harga << endl;
        j++;
        k++;
    }

    // Bayangkan kamu sedang memindahkan buku dari dua meja kecil (L dan R) ke satu rak buku utama (arr).
    // - i adalah tangan kiri kamu yang menunjuk buku di meja L.
    // - j adalah tangan kanan kamu yang menunjuk buku di meja R.
    // - k adalah jari kamu yang menunjuk kotak kosong di rak utama (arr).
    
    // Setiap kali kamu meletakkan satu buku ke rak, kamu harus menggeser jari kamu ke kotak kosong berikutnya 
    // agar buku selanjutnya tidak menimpa buku yang baru saja diletakkan. Proses menggeser jari itulah yang disebut k++.

    delete[] L;
    delete[] R;
}

// Fungsi Rekursif Merge Sort
// mergeSort(arr, 0, 1)
void mergeSort(Produk *arr, int left, int right)
{
    if (left < right)
    {
        // divide
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Fungsi untuk menampilkan isi Array of Struct
void tampilkanData(Produk *arr, int n)
{
    cout << "ID\tNama\tHarga" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        // Mengakses anggota struct menggunakan pointer (ptr->member)
        Produk *ptr = (arr + i);
        cout << ptr->id << "\t" << ptr->nama << "\t" << ptr->harga << endl;
    }
    cout << endl;
}

int main()
{
    int n = 5;
    // Inisialisasi Array of Struct
    Produk daftarProduk[n] = {
        {101, "Laptop", 8000},
        {102, "Mouse ", 150},
        {103, "Monitor", 2500},
        {104, "Keyboard", 500},
        {105, "Camera", 2000}};
    cout << "Data Sebelum Sorting (Berdasarkan Harga):" << endl;
    tampilkanData(daftarProduk, n);

    // Memanggil Merge Sort menggunakan pointer ke array
    mergeSort(daftarProduk, 0, n - 1);
    cout << "Data Setelah Sorting (Merge Sort O(n log n)):" << endl;
    tampilkanData(daftarProduk, n);
    return 0;
}