#include <iostream>
using namespace std;

int binaryinsertionSort()
{
    int arr[8] = { 8,6,5,3,1,2,7,4 };
    int compareKey = 0;
    for (int i = 1; i < 8; i++) {
        compareKey = arr[i];
        int lowIndex = 0, highIndex = i - 1, midIndex;//midIndex�� �ʱ�ȭ�� �ʿ��Ѱ�?
        while (lowIndex < highIndex) {//�񱳺� : O(log n)
            midIndex = (lowIndex + highIndex) / 2;
            if (compareKey >= arr[midIndex]) lowIndex = midIndex + 1;
            else highIndex = midIndex;
        }
        //��ȯ�� : O(n) memcpy(dest, src, size)
        memcpy(arr + highIndex + 1, arr + highIndex, sizeof(arr[0]) * (i - highIndex));
        arr[highIndex] = compareKey;
    }

    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}