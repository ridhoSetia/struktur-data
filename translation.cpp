#include <iostream>
#include <vector>

struct Segment { int base; int limit; };

void SimulasiPaging() {
    int PAGE_SIZE = 4096; // 4 KB Page Size
    std::vector<int> page_table = {5, 2, 8, 1}; // Index = Page, Value = Frame
    int logical_addr = 9500;

    int p = logical_addr / PAGE_SIZE; // Page Number
    int d = logical_addr % PAGE_SIZE; // Offset
    int physical_addr = (page_table[p] * PAGE_SIZE) + d;

    std::cout << "--- A. TRANSLASI ALAMAT PAGING ---\n";
    std::cout << "Logical Address  : " << logical_addr << "\n";
    std::cout << "Page (p) / Offset: Page " << p << ", Offset " << d << " byte\n";
    std::cout << "Physical Address : Frame " << page_table[p] << " -> " << physical_addr << "\n\n";
}

void SimulasiSegmentasi() {
    std::vector<Segment> segment_table = {{1400, 1000}, {6300, 400}, {4300, 500}};
    int seg_num = 1; // Segment Data
    int offset = 250;

    std::cout << "--- B. TRANSLASI ALAMAT SEGMENTASI ---\n";
    std::cout << "Logical Address  : Segment " << seg_num << ", Offset " << offset << "\n";
    if (offset < segment_table[seg_num].limit) {
        int physical_addr = segment_table[seg_num].base + offset;
        std::cout << "Status           : Valid Access\n";
        std::cout << "Physical Address : " << physical_addr << "\n";
    } else {
        std::cout << "Status           : TRAP! Segment Fault (Offset > Limit)\n";
    }
}

int main() {
    SimulasiPaging();
    SimulasiSegmentasi();
    return 0;
}
