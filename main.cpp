
#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
T* init_array(size_t size)
{
    T* arr = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = -10+T(rand() % 50);
    }
    return arr;
}

template <typename T>
void print_array(T* arr, int size = -1)
{
    if (size == -1)
    {
        size = _msize(arr) / sizeof * arr;
    }


    T* arr3 = new T[size];
    int count = 0;

    for (size_t i = 0; i < size; i++)
    {
        bool found = false;
        for (int j = 0; j <= count; j++) {
            if (arr[i] < 0) {
                found = true;
                break;
            }
        }
        if (!found) {
            arr3[count] = arr[i];
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

    cout << "Enter size for massive: ";
    int size;
    cin >> size;
    int* arr_i = init_array<int>(size);
    cout << "==================================" << endl;
    cout << "Massive: ";
    print_array_for_one_massive<int>(arr_i);

    cout << "==================================" << endl;

    cout << "Result: ";
    print_array<int>(arr_i);

    delete[] arr_i;


    return 0;
}