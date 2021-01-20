#include <iostream>
using namespace std;

int insertionSort()
{
    int arr[8] = { 8,6,5,3,1,2,7,4 };
    int compareKey = 0;
    for (int i = 1; i < 8; i++) {
        compareKey = arr[i];
        int currentIndex = i;
        while (currentIndex > 0 && (arr[currentIndex - 1] > compareKey)) {
            arr[currentIndex] = arr[currentIndex - 1];
            currentIndex--;
        }
        arr[currentIndex] = compareKey;
    }
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}