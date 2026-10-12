# SIMULASI ALGORITMA NEXT-FIT

def NextFit(blockSize, m, processSize, n):
    """
    Function untuk mensimulasikan alokasi memori dengan algoritma Next-Fit.

    Param:
    blockSize   : List berisi ukuran masing-masing blok memori (RAM)
    m           : Jumlah total blok memori
    processSize : List berisi ukuran masing-masing proses yang meminta memori
    n           : Jumlah total proses
    """
    # List allocation menyimpan indeks blok memori yang dialokasikan untuk tiap proses.
    # Inisialisasi awal bernilai -1 (artinya belum dialokasikan).
    allocation = [-1] * n

    # Inisialisasi pointer pencarian (j) dan titik batas pencarian sirkular (t)
    j = 0
    t = m - 1

    # Iterasi untuk setiap proses yang membutuhkan memori
    for i in range(n):

        # Lakukan pencarian blok memori tanpa mengulang dari indeks 0
        while j < m:
            # Cek apakah blok memori j saat ini mencukupi untuk proses i
            if blockSize[j] >= processSize[i]:

                # Alokasikan blok j untuk proses i
                allocation[i] = j

                # Kurangi kapasitas memori yang tersedia pada blok j tersebut
                blockSize[j] -= processSize[i]

                # Perbarui titik akhir/penanda putaran pencarian sirkular
                t = (j - 1) % m
                break

            # Jika pointer telah berputar dan kembali ke titik alokasi terakhir
            if t == j:
                t = (j - 1) % m
                # Hentikan perulangan karena seluruh blok sudah diperiksa
                break

            # Pergerakan pointer secara sirkular menggunakan operator modulo %
            j = (j + 1) % m

    # Display hasil alokasi memori dalam format tabel
    print("\n========================================================")
    print("         HASIL ALOKASI MEMORI (ALGORITMA NEXT-FIT)       ")
    print("========================================================")
    print("No. Proses\tUkuran Proses\tNo. Blok Memori")
    print("--------------------------------------------------------")
    for i in range(n):
        print(f"  Proses {i + 1}\t\t{processSize[i]} KB\t\t", end="")
        if allocation[i] != -1:
            print(f"Blok {allocation[i] + 1}")
        else:
            print("Tidak Dialokasikan (Gagal)")
    print("========================================================\n")

# PROGRAM UTAMA
if __name__ == '__main__':
    # Kasus Uji Awal:
    # Daftar ukuran blok memori yang tersedia di RAM (dalam KB)
    blockSize = [26, 91, 100]

    # Daftar ukuran proses yang meminta memori (dalam KB)
    processSize = [26, 91, 100]

    m = len(blockSize)
    n = len(processSize)

    print("Kapasitas Blok Memori Awal : [5 KB, 10 KB, 20 KB]")
    print("Kebutuhan Ukuran Proses    : [10 KB, 20 KB, 5 KB]")

    # Eksekusi fungsi NextFit
    NextFit(blockSize, m, processSize, n)
