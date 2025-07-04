#include "bubble_sort.h"
#include <algorithm>

void bubbleSort(int* v, int n, Metrics& m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            m.comparacoes++;
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                m.trocas++;
            }
        }
    }
}
