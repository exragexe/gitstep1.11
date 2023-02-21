
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
    for (size_t i = 0; i < size; i++)
    {
        cout << *(arr + i) << ' ';
    }
    cout << endl;
}

template<typename T>
bool addarr(T* &arr, int &size, T* items, int num_items){
    size_t old_size = size;
    size += num_items;
    T* buffer = new T[size];
    for (size_t i = 0; i < old_size; i++) {
        buffer[i] = arr[i];
    }
    for (size_t i = 0; i < num_items; i++) {
        buffer[old_size+i] = items[i];
    }
    delete[] arr;
    arr = buffer;
    return true;
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
    int new_items_count;
    cout << "Enter the number of new items to add: ";
    cin >> new_items_count;
    int* item = init_array<int>(new_items_count);
    cout << "Elements: ";
    for (int i = 0; i < new_items_count; ++i) {
        cout << item[i]<<"  ";
    }
    cout <<endl;

    cout << "==================================" << endl;
    cout << "Massive: ";
    print_array_for_one_massive<int>(arr_i);
    cout << "==================================" << endl;

    cout << "Result: ";
    addarr(arr_i,size,item,new_items_count);

    print_array(arr_i) ;

    delete[] arr_i;


    return 0;
}