#include <iostream>
using namespace std;

void minMaxSelectionSort(int arr[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        int minVal = arr[i];
        int maxVal = arr[i];
        int minIdx = i;
        int maxIdx = i;
        for (int k = i; k <= j; k++) {
            if (arr[k] > maxVal) {
                maxVal = arr[k];
                maxIdx = k;
            } else if (arr[k] < minVal) {
                minVal = arr[k];
                minIdx = k;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;

        if (arr[minIdx] == maxVal) {
            temp = arr[j];
            arr[j] = arr[minIdx];
            arr[minIdx] = temp;
        } else {
            temp = arr[j];
            arr[j] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
        i++;
        j--;
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    minMaxSelectionSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    delete[] arr;
    return 0;
}
