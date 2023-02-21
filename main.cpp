
#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
T* init_array(size_t size)
{
    T* arr = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = -10+T(rand() % 20);
    }
    return arr;
}

void print_array(int* arr, int* size)
{
    if (*size == 5)
    {
        *size = _msize(arr) / sizeof * arr;
    }
    int* sum = new int(0);
    int* dob = new int(1);
    cout << "Null array elements: ";
    for (size_t i = 0; i < *size; i++)
    {
        if (arr[i] == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    cout << "Negative array elements: ";
    for (size_t i = 0; i < *size; i++)
    {
        if (arr[i]< 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    cout << "Positive array elements: ";
    for (size_t i = 0; i < *size; i++)
    {
        if (arr[i] > 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;


    delete sum;
    delete dob;
}


int main()
{
    srand(time(0));
    int* size = new int(5);
    int* massive = init_array<int>(*size);
    cout << "Massive:";
    for (size_t i = 0; i < *size; i++)
    {
        cout << massive[i]<<"  ";
    }
    cout << endl;
    print_array(massive, size);

    delete[] massive;
    delete size;

    return 0;
}