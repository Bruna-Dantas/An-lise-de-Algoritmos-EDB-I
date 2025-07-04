#include "insertion_sort.h"

void insertionSort(int* v, int n, Metrics& m) {
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0) {
            m.comparacoes++;
            if (v[j] > key) {
                v[j + 1] = v[j];
                m.trocas++;
                j--;
            } else break;
        }
        v[j + 1] = key;
    }
}