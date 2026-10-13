#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

int FIFO_Faults(const std::vector<int>& pages, int capacity) {
    std::unordered_set<int> s;
    std::queue<int> indexes;
    int faults = 0;
    for (int p : pages) {
        if (s.size() < capacity) {
            if (s.find(p) == s.end()) { s.insert(p); indexes.push(p); faults++; }
        } else {
            if (s.find(p) == s.end()) {
                int val = indexes.front(); indexes.pop();
                s.erase(val); s.insert(p); indexes.push(p); faults++;
            }
        }
    }
    return faults;
}

int LRU_Faults(const std::vector<int>& pages, int capacity) {
    std::unordered_set<int> s;
    std::unordered_map<int, int> last_used;
    int faults = 0;
    for (size_t i = 0; i < pages.size(); i++) {
        if (s.size() < capacity) {
            if (s.find(pages[i]) == s.end()) { s.insert(pages[i]); faults++; }
            last_used[pages[i]] = i;
        } else {
            if (s.find(pages[i]) == s.end()) {
                int lru_val = -1, min_time = 99999;
                for (int page : s) {
                    if (last_used[page] < min_time) { min_time = last_used[page]; lru_val = page; }
                }
                s.erase(lru_val); s.insert(pages[i]); faults++;
            }
            last_used[pages[i]] = i;
        }
    }
    return faults;
}

int main() {
    std::vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    int capacity = 3;
    std::cout << "--- KOMPARASI PAGE REPLACEMENT (Capacity: 3 Frame) ---\n";
    std::cout << "Total Page Faults (FIFO) = " << FIFO_Faults(pages, capacity) << "\n";
    std::cout << "Total Page Faults (LRU)  = " << LRU_Faults(pages, capacity) << "\n";
    return 0;
}
