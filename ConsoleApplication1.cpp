#include <iostream>
#include <chrono>

class Sort {
public:
    void bubbleSort(int arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Schimbăm elementele
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Schimbăm elementele
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr1[100];
    int arr2[100];
    
    int n = sizeof(arr1) / sizeof(arr1[0]);

    for (int i = 0; i < 100; i++) {
        arr1[i] = rand() % 100 + 1;
        arr2[i] = arr1[i];
    }

    std::cout << "string of numbers to sort >>> ";
    for (int i = 0; i < 100; i++) {
        std::cout << arr1[i]<<' ';
    }

    // Măsurarea timpului pentru metoda clasei
    auto startClass = std::chrono::steady_clock::now();
    Sort sort;
    sort.bubbleSort(arr1, n);
    auto endClass = std::chrono::steady_clock::now();
    std::chrono::duration<double> classDuration = endClass - startClass;
    std::cout << "Time taken by class method: " << classDuration.count() << " seconds\n";

    // Măsurarea timpului pentru funcția liberă
    auto startFunction = std::chrono::steady_clock::now();
    bubbleSort(arr2, n);
    auto endFunction = std::chrono::steady_clock::now();
    std::chrono::duration<double> functionDuration = endFunction - startFunction;
    std::cout << "Time taken by free function: " << functionDuration.count() << " seconds\n";

    std::cout << "sort string output >>> ";
    for (int i = 0; i < 100; i++) {
        std::cout << arr1[i]<< ' ';
    }
    return 0;
}
