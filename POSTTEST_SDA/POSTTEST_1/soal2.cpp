#include <iostream>
#include <string>
using namespace std;

int matriks3_3[3][3];

void inputMatriks(string &matriks, int i)
{
    int maksKoma;
    do
    {
        cout << "Masukkan tiap kolom pada baris " << i << " cth(1,2,3): ";
        cin >> matriks;

        maksKoma = 0;
        for (int k = 0; k < matriks.size(); k++)
        {
            if (matriks[k] == ',')
            {
                maksKoma++;
            }
        }

        if (maksKoma != 2)
        {
            cout << "❌ Format salah! Harus ada 2 koma (contoh: 1,2,3).\n";
        }

    } while (maksKoma != 2); // ulang sampai benar
}

int main()
{
    int hasil_diagonal_utama = 0;
    int hasil_diagonal_sekunder = 0;
    int hasil_akhir = 0;
    string matriks;
    string token;
    char pemisah = ',';
    size_t posisi_awal, posisi_pemisah;

    for (int i = 0; i < 3; i++)
    {
        inputMatriks(matriks, i + 1);
        posisi_awal = 0;

        for (int j = 0; j < 3; j++)
        {
            posisi_pemisah = matriks.find(pemisah, posisi_awal);

            if (posisi_pemisah == string::npos)
            {
                token = matriks.substr(posisi_awal);
            }
            else
            {
                token = matriks.substr(posisi_awal, posisi_pemisah - posisi_awal);
                posisi_awal = posisi_pemisah + 1;
            }

            matriks3_3[i][j] = stoi(token);
        }
    }

        cout << "\nMatriks 3x3:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matriks3_3[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                if (i > 1 and j > 1)
                {
                    break;
                }
                
                if (i == 0 && j == 0)
                {
                    hasil_diagonal_utama = matriks3_3[i][j] * matriks3_3[i + 1][j + 1];
                }
                else if (i > 0 && j > 0)
                {
                    cout << "diagonal utama: " << "0,0 *" << " 1,1 *" << " 2,2 = " << hasil_diagonal_utama << "*" << matriks3_3[i + 1][j + 1];
                    hasil_diagonal_utama *= matriks3_3[i + 1][j + 1];
                    cout << " = " << hasil_diagonal_utama << endl;
                }
            }

            if (((i * -1) + 2) == j)
            {
                if (i > 1 and j < 1)
                {
                    break;
                }
                
                if (i == 0 && j == 2)
                {
                    hasil_diagonal_sekunder = matriks3_3[i][j] * matriks3_3[i + 1][j - 1];
                }
                else if (i > 0 && j < 2)
                {
                    cout << "diagonal sekunder: " << "0,2 *" << " 1,1 *" << " 2,0 = " << hasil_diagonal_sekunder << "*" << matriks3_3[i + 1][j - 1];
                    hasil_diagonal_sekunder *= matriks3_3[i + 1][j - 1];
                    cout << " = " << hasil_diagonal_sekunder << endl;
                }
            }
        }
    }

    hasil_akhir = hasil_diagonal_utama + hasil_diagonal_sekunder;

    cout << "Perhitungan = " << hasil_diagonal_utama << " + " << hasil_diagonal_sekunder << " = " << hasil_akhir;

    return 0;
}
