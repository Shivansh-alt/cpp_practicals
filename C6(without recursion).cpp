#include <iostream>

int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, target;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter elements in ascending order: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cout << "Enter the element to search: ";
    std::cin >> target;

    int result = binarySearchIterative(arr, n, target);
    if (result != -1) {
        std::cout << "Element found at position " << result + 1 << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
