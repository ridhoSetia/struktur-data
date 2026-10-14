#include <iostream>
#include <vector>

void ResetData(const std::vector<int>& src_b, const std::vector<int>& src_p, std::vector<int>& b, std::vector<int>& p) {
    b = src_b; p = src_p;
}

// Mencetak satu baris hasil penempatan: nomor blok, ukuran blok sebelum dipakai, dan sisanya.
void CetakBerhasil(size_t proses, int ukuran_proses, size_t blok, int tersedia) {
    std::cout << "  Proses " << proses << " (" << ukuran_proses << " KB) -> Blok " << blok
              << " (tersedia " << tersedia << " KB, sisa " << (tersedia - ukuran_proses) << " KB)\n";
}

void CetakGagal(size_t proses, int ukuran_proses) {
    std::cout << "  Proses " << proses << " (" << ukuran_proses << " KB) -> GAGAL (tidak ada blok >= "
              << ukuran_proses << " KB)\n";
}

void FirstFit(std::vector<int> b, std::vector<int> p) {
    std::cout << "[FIRST-FIT]\n";
    for (size_t i = 0; i < p.size(); i++) {
        bool alloc = false;
        for (size_t j = 0; j < b.size(); j++) {
            if (b[j] >= p[i]) {
                CetakBerhasil(i+1, p[i], j+1, b[j]);
                b[j] -= p[i]; alloc = true; break;
            }
        }
        if (!alloc) CetakGagal(i+1, p[i]);
    }
}

void BestFit(std::vector<int> b, std::vector<int> p) {
    std::cout << "\n[BEST-FIT]\n";
    for (size_t i = 0; i < p.size(); i++) {
        int best = -1;
        for (size_t j = 0; j < b.size(); j++) {
            if (b[j] >= p[i]) {
                if (best == -1 || b[j] < b[best]) best = j;
            }
        }
        if (best != -1) {
            CetakBerhasil(i+1, p[i], best+1, b[best]);
            b[best] -= p[i];
        } else CetakGagal(i+1, p[i]);
    }
}

void WorstFit(std::vector<int> b, std::vector<int> p) {
    std::cout << "\n[WORST-FIT]\n";
    for (size_t i = 0; i < p.size(); i++) {
        int worst = -1;
        for (size_t j = 0; j < b.size(); j++) {
            if (b[j] >= p[i]) {
                if (worst == -1 || b[j] > b[worst]) worst = j;
            }
        }
        if (worst != -1) {
            CetakBerhasil(i+1, p[i], worst+1, b[worst]);
            b[worst] -= p[i];
        } else CetakGagal(i+1, p[i]);
    }
}

void NextFit(std::vector<int> b, std::vector<int> p) {
    std::cout << "\n[NEXT-FIT]\n";
    size_t j = 0;
    for (size_t i = 0; i < p.size(); i++) {
        bool alloc = false; size_t count = 0;
        while (count < b.size()) {
            if (b[j] >= p[i]) {
                CetakBerhasil(i+1, p[i], j+1, b[j]);
                b[j] -= p[i]; alloc = true; break;
            }
            j = (j + 1) % b.size(); count++;
        }
        if (!alloc) CetakGagal(i+1, p[i]);
    }
}

int main() {
    std::vector<int> init_b = {100, 500, 200, 300, 600};
    std::vector<int> init_p = {212, 417, 112, 426};
    std::vector<int> b, p;

    std::cout << "DATA AWAL\n  Blok bebas:";
    for (size_t j = 0; j < init_b.size(); j++) std::cout << "  Blok " << (j+1) << " = " << init_b[j] << " KB";
    std::cout << "\n  Proses    :";
    for (size_t i = 0; i < init_p.size(); i++) std::cout << "  Proses " << (i+1) << " = " << init_p[i] << " KB";
    std::cout << "\n\n";

    ResetData(init_b, init_p, b, p); FirstFit(b, p);
    ResetData(init_b, init_p, b, p); BestFit(b, p);
    ResetData(init_b, init_p, b, p); WorstFit(b, p);
    ResetData(init_b, init_p, b, p); NextFit(b, p);
    return 0;
}