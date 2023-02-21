
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
void print_array(T* arr,char* str, int size = -1, int size2 = -1)
{
    if (size == -1)
    {
        size = _msize(arr) / sizeof * arr;
    }


    T* arr3 = new T[size + size2];
    int count = 0;

    if (*str == 'e') {
        for (size_t i = 0; i < size; i++)
        {
            bool found = false;
            for (int j = 0; j < count; j++) {
                if (arr[i] % 2==0) {
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
    }
    else if (*str == 'o') {
        for (size_t i = 0; i < size; i++)
        {
            bool found = false;
            for (int j = 0; j < count; j++) {
                if (arr[i] % 3==0) {
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
    }
    else {
        cout << "Error";
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
    cout << "First massive: ";
    print_array_for_one_massive<int>(arr_i);

    cout << "==================================" << endl;
    cout << "======Enter what number u want delete=======" << endl << "Even or odd numbers(e or o): ";
    char* str = new char;
    cin >> str;
    cout << "Third massive: ";
    print_array<int>(arr_i, str);

    delete[] arr_i;


    return 0;
}