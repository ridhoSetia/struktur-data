#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // 1. Inisialisasi Blok Memori: Blok 0 (150KB), Blok 1 (150KB), Blok 2 (350KB)
    std::vector<int> blocks = {150, 150, 350}; // Total = 650 KB
    int p1 = 300, p2 = 25, p3 = 125; 

    // Simulasi Skenario Alokasi Berdasarkan Logika:
    blocks[2] -= p1; // P1 (300 KB) dialokasikan di Blok 3 (Indeks 2) -> Sisa 50 KB
    blocks[0] -= p2; // P2 (25 KB) dialokasikan di Blok 1 (Indeks 0)  -> Sisa 125 KB    
    blocks[0] -= p3; // P3 (125 KB) dialokasikan di Blok 1 (Indeks 0) -> Sisa 0 KB
    // Blok 2 (Indeks 1) tidak dipakai -> Sisa tetap 150 KB

    // Hitung total memori bebas menggunakan std::accumulate
    int total_free = std::accumulate(blocks.begin(), blocks.end(), 0); // Total: 0 + 150 + 50 = 200 KB
    int new_process = 180; // Permintaan proses baru sebesar 180 KB

    std::cout << "=================================================\n";
    std::cout << " 1. KONDISI AWAL (FRAGMENTASI EKSTERNAL)\n";
    std::cout << "=================================================\n";
    std::cout << "Sisa Memori Bebas Terpisah : Blok1=" << blocks[0] << " KB, "
              << "Blok2=" << blocks[1] << " KB, "
              << "Blok3=" << blocks[2] << " KB\n";
    std::cout << "Total Memori Bebas RAM     : " << total_free << " KB\n";
    std::cout << "Permintaan Proses Baru     : " << new_process << " KB\n";
    std::cout << "Status Alokasi Kontigu     : GAGAL! (Tidak ada satu blok yang cukup >= 180 KB)\n\n";

    std::cout << "=================================================\n";
    std::cout << " 2. SETELAH DIJALANKAN KOMPAKSI MEMORI (COMPACTION)\n";
    std::cout << "=================================================\n";
    
    // Proses Kompaksi: Menggeser semua area bebas dan menyatukannya
    int compacted_block = total_free; // 200 KB disatukan menjadi 1 blok besar
    
    std::cout << "Hasil Blok Kontigu Baru    : " << compacted_block << " KB\n";
    if (compacted_block >= new_process) {
        std::cout << "Status Alokasi Kontigu     : BERHASIL! (Proses 180 KB berhasil dimuat)\n";
        
        // Simulasi alokasi setelah kompaksi
        compacted_block -= new_process;
        std::cout << "Sisa Memori Setelah Dimuat : " << compacted_block << " KB\n";
    }
    
    std::cout << "=================================================\n";

    return 0;
}
