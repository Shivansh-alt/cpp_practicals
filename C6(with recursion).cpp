#include <iostream>

int binarySearchRecursive(int arr[], int low, int high, int target) {
    if(low > high) return -1;
    int mid = low + (high - low) / 2;
    if(arr[mid] == target) return mid;
    if(arr[mid] > target) return binarySearchRecursive(arr, low, mid - 1, target);
    return binarySearchRecursive(arr, mid + 1, high, target);
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter elements in ascending order: ";
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int target;
    std::cout << "Enter the element to search: ";
    std::cin >> target;
    int result = binarySearchRecursive(arr, 0, n - 1, target);
    if(result != -1) std::cout << "Element found at position " << result + 1 << std::endl;
    else std::cout << "Element not found" << std::endl;
    return 0;
}
