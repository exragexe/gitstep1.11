
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
bool removearr(T* &arr, int &size, int start_index, int num_items){
    if (start_index < 0 || start_index >= size) {
        return false;
    }
    int end_index = start_index + num_items;
    if (end_index > size) {
        num_items = size - start_index;
        end_index = size;
    }
    size_t old_size = size;
    size -= num_items;
    T* buffer = new T[size];
    for (size_t i = 0; i < start_index; i++) {
        buffer[i] = arr[i];
    }
    for (size_t i = end_index; i < old_size; i++) {
        buffer[i - num_items] = arr[i];
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
    int remove_start_index;
    int remove_items_count;
    cout << "Enter the start index to remove from: ";
    cin >> remove_start_index;
    cout << "Enter the number of items to remove: ";
    cin >> remove_items_count;
    cout <<endl;
    cout << "==================================" << endl;
    cout << "Massive: ";
    print_array_for_one_massive<int>(arr_i, size);
    cout << "==================================" << endl;

    cout << "Result: ";
    removearr(arr_i, size, remove_start_index, remove_items_count);

    print_array(arr_i, size);

    delete[] arr_i;

    return 0;
}
