#include "quick_sort.h"
#include <algorithm>

int partition(int* v, int low, int high, Metrics& m) {
    int pivot = v[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        m.comparacoes++;
        if (v[j] <= pivot) {
            i++;
            std::swap(v[i], v[j]);
            m.trocas++;
        }
    }
    std::swap(v[i + 1], v[high]);
    m.trocas++;
    return i + 1;
}

void quickSortAux(int* v, int low, int high, Metrics& m) {
    if (low < high) {
        int pi = partition(v, low, high, m);
        quickSortAux(v, low, pi - 1, m);
        quickSortAux(v, pi + 1, high, m);
    }
}

void quickSort(int* v, int n, Metrics& m) {
    quickSortAux(v, 0, n - 1, m);
}
