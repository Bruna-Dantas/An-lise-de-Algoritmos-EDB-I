#include "selection_sort.h"
#include <algorithm>

void selectionSort(int* v, int n, Metrics& m) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            m.comparacoes++;
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(v[i], v[min_idx]);
            m.trocas++;
        }
    }
}