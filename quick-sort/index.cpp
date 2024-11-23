#include <stdio.h>
#include <iostream>

using namespace std;

void swapPointers(int *A, int p1, int p2) {
  int temp = A[p1];
  A[p1] = A[p2];
  A[p2] = temp;
}

void quicksort(int *A, int lowIndex, int highIndex) {
  if (lowIndex >= highIndex) {
    return;
  }

  int pivot = A[highIndex];
  int leftPointer = lowIndex, rightPointer = highIndex;

  while (leftPointer < rightPointer) {
    while (A[leftPointer] <= pivot && leftPointer < rightPointer) {
      leftPointer++;
    }
    // cout << "left: " << A[leftPointer] << " ";
    while (A[rightPointer] >= pivot && leftPointer < rightPointer) {
      rightPointer--;
    }
    // cout << "right: " << A[rightPointer] << " ";
    swapPointers(A, leftPointer, rightPointer);
  }
  swapPointers(A, leftPointer, highIndex);

  quicksort(A, lowIndex, leftPointer - 1);
  quicksort(A, leftPointer + 1, highIndex);
}


int main() {
  int size = 10;
  int A[size] = {8, 12, 1, 54, 55, 31, 41, 3, 77, 2};

  cout << "Unsorted: ";
  for (int i = 0; i < size; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  quicksort(A, 0, size - 1);

  cout << "Sorted: ";
  for (int i = 0; i < size; i++) {
    cout << A[i] << " ";
  }

  return 0;
}