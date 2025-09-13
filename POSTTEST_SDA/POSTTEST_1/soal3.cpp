#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    int nim;
    float ipk;
};

struct Ipk
{
    Mahasiswa detailInfo;
};

Ipk isiData[5];

void inputMahasiswa(Ipk *data)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "-- Masukkan data mahasiswa " << i+1 << "--" << endl;
        cout << "Nama: ";
        cin >> data[i].detailInfo.nama;
        cout << "NIM: ";
        cin >> data[i].detailInfo.nim;
        cout << "IPK: ";
        cin >> data[i].detailInfo.ipk;
    }
}

void cariIpkTertinggi(Ipk *data)
{
    float maxIpk = data[0].detailInfo.ipk;

    // Cari nilai IPK tertinggi
    for (int i = 1; i < 5; i++)
    {
        if (data[i].detailInfo.ipk > maxIpk)
        {
            maxIpk = data[i].detailInfo.ipk;
        }
    }

    // Tampilkan semua mahasiswa dengan IPK tertinggi
    cout << "\n=== Mahasiswa dengan IPK tertinggi (" << maxIpk << ") ===" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (data[i].detailInfo.ipk == maxIpk)
        {
            cout << "Nama: " << data[i].detailInfo.nama << endl;
            cout << "NIM : " << data[i].detailInfo.nim << endl;
            cout << "IPK : " << data[i].detailInfo.ipk << endl;
            cout << "--------------------------" << endl;
        }
    }

    int idxMaks = 0; // simpan indeks sementara dengan IPK tertinggi
    for (int i = 1; i < 5; i++)
    {
        if (data[i].detailInfo.ipk > data[idxMaks].detailInfo.ipk)
        {
            idxMaks = i;
        }
    }

    cout << "\nMahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama: " << data[idxMaks].detailInfo.nama << endl;
    cout << "NIM : " << data[idxMaks].detailInfo.nim << endl;
    cout << "IPK : " << data[idxMaks].detailInfo.ipk << endl;
}


int main()
{
    inputMahasiswa(isiData);

    cariIpkTertinggi(isiData);

    return 0;
}
