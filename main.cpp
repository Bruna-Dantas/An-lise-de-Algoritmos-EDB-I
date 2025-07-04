#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "metrics.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

using namespace std;

void gerarAleatorio(int* v, int n) {
    for (int i = 0; i < n; i++) v[i] = rand() % 10000;
}

void gerarQuaseOrdenado(int* v, int n) {
    for (int i = 0; i < n; i++) v[i] = i;
    for (int i = 0; i < n / 10; i++) swap(v[rand() % n], v[rand() % n]);
}

void gerarInversamenteOrdenado(int* v, int n) {
    for (int i = 0; i < n; i++) v[i] = n - i;
}

double medirTempo(void (*sortFunc)(int*, int, Metrics&), int* v, int n, Metrics& m) {
    clock_t inicio = clock();
    sortFunc(v, n, m);
    clock_t fim = clock();
    return double(fim - inicio) / CLOCKS_PER_SEC;
}

void testarAlgoritmo(void (*sortFunc)(int*, int, Metrics&), string nome, int* original, int n) {
    int* copia = new int[n];
    copy(original, original + n, copia);

    Metrics m;
    double tempo = medirTempo(sortFunc, copia, n, m);

    cout << nome << " | Tamanho: " << n 
         << " | Tempo: " << tempo << "s"
         << " | Comparacoes: " << m.comparacoes
         << " | Trocas: " << m.trocas << endl;

    delete[] copia;
}

int main() {
    srand(time(NULL));
    const int tamanhos[] = {100, 1000, 5000};
    const int numTamanhos = 3;

    for (int t = 0; t < numTamanhos; t++) {
        int n = tamanhos[t];
        int* vetor = new int[n];

        cout << "\n===== TAMANHO: " << n << " =====\n";

        cout << "\nTipo: Aleatorio\n";
        gerarAleatorio(vetor, n);
        testarAlgoritmo(bubbleSort, "Bubble Sort", vetor, n);
        testarAlgoritmo(insertionSort, "Insertion Sort", vetor, n);
        testarAlgoritmo(selectionSort, "Selection Sort", vetor, n);
        testarAlgoritmo(mergeSort, "Merge Sort", vetor, n);
        testarAlgoritmo(quickSort, "Quick Sort", vetor, n);

        cout << "\nTipo: Quase Ordenado\n";
        gerarQuaseOrdenado(vetor, n);
        testarAlgoritmo(bubbleSort, "Bubble Sort", vetor, n);
        testarAlgoritmo(insertionSort, "Insertion Sort", vetor, n);
        testarAlgoritmo(selectionSort, "Selection Sort", vetor, n);
        testarAlgoritmo(mergeSort, "Merge Sort", vetor, n);
        testarAlgoritmo(quickSort, "Quick Sort", vetor, n);

        cout << "\nTipo: Inversamente Ordenado\n";
        gerarInversamenteOrdenado(vetor, n);
        testarAlgoritmo(bubbleSort, "Bubble Sort", vetor, n);
        testarAlgoritmo(insertionSort, "Insertion Sort", vetor, n);
        testarAlgoritmo(selectionSort, "Selection Sort", vetor, n);
        testarAlgoritmo(mergeSort, "Merge Sort", vetor, n);
        testarAlgoritmo(quickSort, "Quick Sort", vetor, n);

        delete[] vetor;
    }

    return 0;
}