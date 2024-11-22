#include <stdio.h>
#include <iostream>

using namespace std;

void merge(
  int* inputArray,
  int* leftPart, 
  int leftLength, 
  int* rightPart, 
  int rightLength
) {
  int i = 0, j = 0, k = 0;
 
  while (i < leftLength && j < rightLength) {
    if (leftPart[i] <= rightPart[j]) {
      inputArray[k] = leftPart[i];
      i++;
    } else {
      inputArray[k] = rightPart[j];
      j++;
    }
    k++;
  }

  while (i < leftLength) {
    inputArray[k] = leftPart[i];
    i++, k++;
  }

  while (j < rightLength) {
    inputArray[k] = rightPart[j];
    j++, k++;
  }
}

void mergeSort(int* inputArray, int length) {

  // controlling is length (n)
  if (length < 2) {
    return;
  }

  int leftIndex = length / 2, 
      rightIndex = length - leftIndex, 
      leftPart[leftIndex], 
      rightPart[rightIndex];

  // initialize two arrays on each call (half of the last length)
  for (int i = 0; i < leftIndex; i++) {
    leftPart[i] = inputArray[i];
  }

  for (int i = leftIndex; i < length; i++) {
    rightPart[i - leftIndex] = inputArray[i];
  }

  // recursive call on both halves
  mergeSort(leftPart, leftIndex);
  mergeSort(rightPart, rightIndex);

  // on each call we will merge
  merge(inputArray, leftPart, leftIndex, rightPart, rightIndex);
}

int main() {
  int array[5] = { 83, 41, 12, 60, 2 };
  int arrayLength = sizeof(array) / sizeof(array[0]);

  cout << "Before: ";
  for (int i = 0; i < arrayLength; i++) {
    cout << array[i] << " ";
  }
  cout << endl;

  mergeSort(array, arrayLength);

  cout << "After: ";
  for (int i = 0; i < arrayLength; i++) {
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}