/*  Bubble Sort
 - Give the array as well as n , which is the length of the array.
 - call the function, by specifying the array and the length of the array.
 - This code sorts in ascending order

  Time Complexity: O(N^2)
  Auxiliary Space: O(1)
*/
#include <iostream>
#include <cmath>
using namespace std;

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {5, 1, 4, 2, 8, 10, 3, 1001, 17, 0};
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}