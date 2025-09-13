#include <iostream>
using namespace std;

int arrayAngka[] = {9, 12, 15, 18, 21, 24, 27};

void balikUrutan(int *array, int ukuran)
{
        int start = 0;
        int end = ukuran - 1;

        while (start < end) {
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;

            start++;
            end--;
        }

        for (int i = 0; i < ukuran; i++) {
            cout << array[i] << " ";
        }
}

int main()
{
    int ukuran = sizeof(arrayAngka) / sizeof(arrayAngka[0]);
    
    cout << "Sebelum dibalik: ";
    for (int i = 0; i < ukuran; i++) {
        cout << arrayAngka[i] << " ";
    }
    cout << endl;

    cout << "Setelah dibalik: ";
    balikUrutan(arrayAngka, ukuran);

    return 0;
}
