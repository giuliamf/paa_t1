#include <iostream>
#include <vector>
using namespace std;

// Função merge que junta dois subarrays ordenados
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // tamanho do primeiro subarray
    int n2 = right - mid;    // tamanho do segundo subarray

    vector<int> L(n1), R(n2);

    // Copia dados para os vetores temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Junta os vetores de volta em arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copia os elementos restantes de L[]
    while (i < n1)
        arr[k++] = L[i++];

    // Copia os elementos restantes de R[]
    while (j < n2)
        arr[k++] = R[j++];
}

// Função recursiva de merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // evita overflow

        mergeSort(arr, left, mid);        // ordena a primeira metade
        mergeSort(arr, mid + 1, right);   // ordena a segunda metade
        merge(arr, left, mid, right);     // junta as metades ordenadas
    }
}

int main() {
    vector<int> arr;
    int num;

    // Lê todos os números da entrada
    while (cin >> num) {
        arr.push_back(num);
    }

    // Ordena usando merge sort
    mergeSort(arr, 0, arr.size() - 1);

    // Imprime os números ordenados
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}
