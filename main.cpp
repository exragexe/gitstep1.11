
#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
T* init_array(size_t size)
{
    T* arr = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = T(rand() % 10);
    }
    return arr;
}

template <typename T>
void print_array(T* arr, T* arr2, int size = -1, int size2 = -1)
{
    if (size == -1)
    {
        size = _msize(arr) / sizeof * arr;
    }

    if (size2 == -1)
    {
        size2 = _msize(arr2) / sizeof * arr2;
    }

    T* arr3 = new T[size + size2];
    int count = 0;

    for (size_t i = 0; i < size; i++)
    {
        bool found = false;
        for (int j = 0; j < count; j++) {
            if (arr[i] == arr3[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            arr3[count] = arr[i];
            count++;
        }
    }

    for (size_t i = 0; i < size2; i++)
    {
        bool found = false;
        for (int j = 0; j < count; j++) {
            if (arr2[i] == arr3[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            arr3[count] = arr2[i];
            count++;
        }
    }

    for (size_t i = 0; i < count; i++)
    {
        cout << arr3[i] << "  ";
    }
    cout << endl;

    delete[] arr3;
}

template <typename T>
void print_array_for_one_massive(T* arr, int size = -1)
{
    if (size == -1)
    {
        size = _msize(arr) / sizeof * arr;
    }
    for (size_t i = 0; i < size; i++)
    {
        cout << *(arr + i) << "  ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));

    cout << "Enter size for first massive: ";
    int size;
    cin >> size;
    int* arr_i = init_array<int>(size);

    cout << "Enter size for second massive: ";
    int size2;
    cin >> size2;
    cout << "==================================" << endl;
    int* arr_i2 = init_array<int>(size2);
    cout << "First massive: ";
    print_array_for_one_massive<int>(arr_i);
    cout << endl;
    cout << "Second massive: ";
    print_array_for_one_massive<int>(arr_i2);
    cout << "==================================" << endl;
    cout << "Third massive: ";

    print_array<int>(arr_i, arr_i2);

    delete[] arr_i;
    delete[] arr_i2;

    return 0;
}