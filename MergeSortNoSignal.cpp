#include <iostream>
#include <random>
using namespace std;

void print_array(int arr[], int size){
    for (int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* RandArray(int size, double max){
    mt19937 mt(time(nullptr));
    int* a = new int[size];
    for (int i = 0; i < size; ++i)
        a[i] = (mt() % (int)max);
    return a;
};

void Merge(int A[], int p, int q, int r){   // p - firstElemIndex, q - divider, r - lastElemIndex
    int n1 = q - p + 1;
    int L[n1] = {};
    for (int i = 0; i < n1; ++i){
        L[i] = A[p + i];
    }
    int n2 = r - q;
    int R[n2] = {};
    for (int i = 0; i < n2; ++i){
        R[i] = A[q + i + 1];
    }
    int i = 0;
    int j = 0;

    for (int k = p; k <= r; ++k){
        if (L[i] < R[j]) {
            A[k] = L[i];
            ++i;

            if (i == n1){
                ++k;
                for (j; j < n2;){
                    A[k] = R[j];
                    ++j;
                    ++k;
                }
            }

        } else {
            A[k] = R[j];
            ++j;

            if (j == n2){
                ++k;
                for (i; i < n1;){
                    A[k] = L[i];
                    ++i;
                    ++k;
                }
            }

        }
    }
}

void Merge_Sort(int A[], int p, int r){
    if (p < r) {
        int q = (p + r)/2;
        Merge_Sort(A, p, q);
        Merge_Sort(A, q+1, r);
        Merge(A, p, q, r);
    }
}


int main() {
    int size = 10;
    int* arr = RandArray(size, 1000);
    print_array(arr, size);
    Merge_Sort(arr, 0, size-1);
    print_array(arr, size);
}