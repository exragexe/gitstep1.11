
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

void print_array(int* arr, int* size)
{
    if (*size == 5)
    {
        *size = _msize(arr) / sizeof * arr;
    }
    int* sum = new int(0);
    int* dob = new int(1);
    for (size_t i = 0; i < *size; i++)
    {
        *sum += arr[i];
    }
    for (size_t i = 0; i < *size; i++)
    {
        *dob *= arr[i];
    }
    cout << endl;
    cout << "Suma massiva: " << *sum << endl;
    cout << "Dobytok massiva: " << *dob << endl;

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