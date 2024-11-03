#include <iostream>

using namespace std;

int* linearSort(int A[], int n) {
  int min = A[0];
  int max = A[0];

  for (int i = 0; i < n; i++) {
    if (A[i] < min)
      min = A[i];
    if (A[i] > max)
      max = A[i];
  }

  int m = max - min + 1;
  int *B = new int[m];

  for (int i = 0; i < m; i++) {
    B[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    int position = A[i] - min + 1;
    B[position] += 1;
  }

  for (int i = 1; i < m - 1; i++) {
    B[i + 1] += B[i];
  }

  int *C = new int[n];

  for (int i = 0; i < n; i++) {
    int position = A[i] - min + 1;
    C[B[position]] = A[i];
    B[position] -= 1;
  }

  delete[] B;

  for (int i = 0; i < n; i++) {
    A[i] = C[i];
  }

  return C;
}

int main() {
  int size = 4;
  int A[size] = {7, 24, 1, 4};

  int* sorted = linearSort(A, size);

  for (int i = 0; i < size; i++) {
    cout << sorted[i] << " ";
  }
  delete[] sorted;

  return 0;
}
