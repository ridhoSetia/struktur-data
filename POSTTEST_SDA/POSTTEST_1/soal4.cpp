#include <iostream>
using namespace std;

void fungsiTukarVariable(int **a, int **b)
{
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main()
{
    int a, b;

    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;

    cout << "\nSebelum pertukaran: a = " << a << ", b = " << b << endl;

    // ============= Pilih salah satu sesuai soal =============

    // Jika soal GANJIL (gunakan double pointer)
    int *pa = &a;
    int *pb = &b;

    fungsiTukarVariable(&pa, &pb);

    cout << "Sesudah pertukaran: a = " << a << ", b = " << b << endl;

    return 0;
}
