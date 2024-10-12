#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <random>
using namespace std;
// Функция для вывода массива
template <typename T>
void printArray(const T& arr, const string& name) {
    std::cout << name << ": ";
    for (const auto& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    // 1. Создаем вектор данных
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);
    vector<int> data(10);
    for (int& value : data) {
        value = distrib(gen);
    }

    // 2. Копируем вектор для разных сортировок
    vector<int> data_sort(data);
    vector<int> data_partial(data);
    vector<int> data_stable(data);
    list<int> data_list(data.begin(), data.end());
    forward_list<int> data_forward(data.begin(), data.end());

    printArray(data, "original array");

    // 3. Сортировка std::sort
    sort(data_sort.begin(), data_sort.end());
    printArray(data_sort, "std::sort");

    // 4. Частичная сортировка std::partial_sort
    partial_sort(data_partial.begin(), data_partial.begin() + 3, data_partial.end());
    printArray(data_partial, "std::partial_sort (first 3 elem )");

    // 5. Сортировка с сохранением порядка std::stable_sort
    stable_sort(data_stable.begin(), data_stable.end());
    printArray(data_stable, "std::stable_sort");

    // 6. Сортировка списка std::list::sort
    data_list.sort();
    printArray(data_list, "std::list::sort");

    // 7. Сортировка односвязного списка std::forward_list::sort
    data_forward.sort();
    printArray(data_forward, "std::forward_list::sort");

    return 0;
}
