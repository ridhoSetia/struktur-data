#include <iostream>
#include <vector>

void SimulasiFixedPartitioning(const std::vector<int>& processes) {
    std::vector<int> fixed_partitions = {400, 400, 400}; // Partisi Tetap @400 KB
    int total_internal_frag = 0;

    std::cout << "--- 1. SIMULASI FIXED PARTITIONING (Partisi Tetap 400 KB) ---\n";
    for (size_t i = 0; i < processes.size(); i++) {
        if (processes[i] <= fixed_partitions[i]) {
            int frag = fixed_partitions[i] - processes[i];
            total_internal_frag += frag;
            std::cout << "Proses " << (i+1) << " (" << processes[i] << " KB) -> Partisi "
                      << (i+1) << " (400 KB) | Frag. Internal: " << frag << " KB\n";
        }
    }
    std::cout << "TOTAL FRAGMENTASI INTERNAL = " << total_internal_frag << " KB\n\n";
}

void SimulasiDynamicPartitioning(const std::vector<int>& processes) {
    int total_ram = 1200; // 1200 KB RAM Bebas
    int current_free = total_ram;

    std::cout << "--- 2. SIMULASI DYNAMIC PARTITIONING (Partisi Presisi Dinamis) ---\n";
    for (size_t i = 0; i < processes.size(); i++) {
        std::cout << "Proses " << (i+1) << " (" << processes[i] << " KB) -> Partisi Dibuat Presisi "
                  << processes[i] << " KB\n";
        current_free -= processes[i];
    }
    std::cout << "Sisa Memori Kontigu Bebas = " << current_free << " KB\n";
    std::cout << "TOTAL FRAGMENTASI INTERNAL = 0 KB (Bebas Pemborosan Dalam)\n\n";
}

int main() {
    std::vector<int> processes = {150, 380, 200}; // Kebutuhan Proses
    SimulasiFixedPartitioning(processes);
    SimulasiDynamicPartitioning(processes);
    return 0;
}
