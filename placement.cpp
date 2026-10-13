#include <iostream>
#include <vector>

void ResetData(const std::vector<int>& src_b, const std::vector<int>& src_p, std::vector<int>& b, std::vector<int>& p) {
    b = src_b; p = src_p;
}

void FirstFit(std::vector<int> b, std::vector<int> p) {
    std::cout << "[FIRST-FIT]\n";
    for (size_t i = 0; i < p.size(); i++) {
        bool alloc = false;
        for (size_t j = 0; j < b.size(); j++) {
            if (b[j] >= p[i]) {
                std::cout << "  Proses " << (i+1) << " (" << p[i] << " KB) -> Blok " << (j+1) << "\n";
                b[j] -= p[i]; alloc = true; break;
            }
        }
        if (!alloc) std::cout << "  Proses " << (i+1) << " -> GAGAL\n";
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
            std::cout << "  Proses " << (i+1) << " (" << p[i] << " KB) -> Blok " << (best+1) << "\n";
            b[best] -= p[i];
        } else std::cout << "  Proses " << (i+1) << " -> GAGAL\n";
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
            std::cout << "  Proses " << (i+1) << " (" << p[i] << " KB) -> Blok " << (worst+1) << "\n";
            b[worst] -= p[i];
        } else std::cout << "  Proses " << (i+1) << " -> GAGAL\n";
    }
}

void NextFit(std::vector<int> b, std::vector<int> p) {
    std::cout << "\n[NEXT-FIT]\n";
    size_t j = 0;
    for (size_t i = 0; i < p.size(); i++) {
        bool alloc = false; size_t count = 0;
        while (count < b.size()) {
            if (b[j] >= p[i]) {
                std::cout << "  Proses " << (i+1) << " (" << p[i] << " KB) -> Blok " << (j+1) << "\n";
                b[j] -= p[i]; alloc = true; break;
            }
            j = (j + 1) % b.size(); count++;
        }
        if (!alloc) std::cout << "  Proses " << (i+1) << " -> GAGAL\n";
    }
}

int main() {
    std::vector<int> init_b = {100, 500, 200, 300, 600};
    std::vector<int> init_p = {212, 417, 112, 426};
    std::vector<int> b, p;

    ResetData(init_b, init_p, b, p); FirstFit(b, p);
    ResetData(init_b, init_p, b, p); BestFit(b, p);
    ResetData(init_b, init_p, b, p); WorstFit(b, p);
    ResetData(init_b, init_p, b, p); NextFit(b, p);
    return 0;
}
