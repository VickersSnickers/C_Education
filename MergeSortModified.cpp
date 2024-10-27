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

int Merge(int A[], int p, int q, int r){   // p - firstElemIndex, q - divider, r - lastElemIndex
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
    int i = 0, j = 0, k = p, pairs = 0;

    while (i < n1 && j < n2){
        if (L[i] < R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
            pairs += n1 - i; // If elem from L (L1) > elem form R (R1) =>> all elems from L, which > L1 =>> R1
        }
        ++k;
    }
    while (i < n1){
        A[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2){
        A[k] = R[j];
        ++j;
        ++k;
    }

    return pairs;
    
}

int Merge_Sort(int A[], int p, int r){
    int pairs = 0;
    if (p < r) {
        int q = (p + r)/2;
        pairs += Merge_Sort(A, p, q);
        pairs += Merge_Sort(A, q+1, r);
        pairs += Merge(A, p, q, r);
    }
    return pairs;
}


int main() {
    int size = pow(10, 3);
    int* arr = RandArray(size, pow(2, 32));
    cout << "Найдено " << Merge_Sort(arr, 0, size-1) << " пар" << endl;   
}