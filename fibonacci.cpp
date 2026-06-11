#include <iostream>
using namespace std;

// Fungsi Fibonacci Search
// arr : pointer ke array (bisa juga ditulis int arr[])
// n : jumlah elemen
// target : nilai yang dicari
// return : indeks jika ketemu, -1 jika tidak

int fibonacciSearch(int *arr, int n, int target)
{

    int fib2 = 0; // F(k-2)
    int fib1 = 1; // F(k-1)
    int fib = 1;  // F(k) = fib1 + fib2

    while (fib < n)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1)
    {
        int i = offset + fib2;
        if (i >= n) i = n - 1; // jangan lewati batas array

        if (arr[i] == target)
        {
            return i;
        }

        else if (arr[i] < target)
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;

            offset = i;
        }

        else {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }

        // Periksa satu elemen tersisa
        if (fib1 == 1 && arr[offset + 1] == target)
            return offset + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = 11;

    int hasil = fibonacciSearch(arr, n, 100);

    if (hasil != -1)
    {
        cout << "searching ketemu di index" << hasil << endl;
    }
    else {
        cout << "gak ada angka itu di array" << endl;
    }
    
}
