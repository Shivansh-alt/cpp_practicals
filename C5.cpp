#include <iostream>

void mergeArrays(int arr1[], int m, int arr2[], int n, int result[]) {
    int i = 0, j = 0, k = 0;
    while(i < m && j < n) {
        if(arr1[i] < arr2[j]) {
            result[k] = arr1[i];
            i++;
        } else {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i < m) {
        result[k] = arr1[i];
        i++; k++;
    }
    while(j < n) {
        result[k] = arr2[j];
        j++; k++;
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int m, n;
    std::cout << "Enter size of first array: ";
    std::cin >> m;
    int arr1[m];
    std::cout << "Enter elements of first array in ascending order: ";
    for(int i = 0; i < m; i++) {
        std::cin >> arr1[i];
    }

    std::cout << "Enter size of second array: ";
    std::cin >> n;
    int arr2[n];
    std::cout << "Enter elements of second array in ascending order: ";
    for(int i = 0; i < n; i++) {
        std::cin >> arr2[i];
    }

    int result[m + n];
    mergeArrays(arr1, m, arr2, n, result);

    std::cout << "First array: ";
    printArray(arr1, m);
    std::cout << "Second array: ";
    printArray(arr2, n);
    std::cout << "Merged array: ";
    printArray(result, m + n);

    return 0;
}
