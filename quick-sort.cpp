#include <iostream>
#include <vector>
using namespace std;

// In quick sort we focus on finding the correct position of value at pivot index.
void quickSort(vector<int> &arr, int lb, int ub) {
    // base case
    if(lb >= ub)
        return;

    int pivot = lb, l = lb, r = ub, temp;

    // repeat untill l < r
    while(l < r) {
        // increase l untill arr[l] > arr[pivot]
        // also l cannot be greater than r
        while(arr[l] <= arr[pivot] && l < r) {
            l++;
        }

        // decrease r untill arr[r] < arr[pivot]
        while(arr[r] > arr[pivot]) {
            r--;
        }

        // if l < r then swap arr[l] and arr[r]
        if(l < r) {
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
        }
    }

    // swap arr[pivot] and arr[r]
    temp = arr[pivot];
    arr[pivot] = arr[r];
    arr[r] = temp;

    // break arr in two parts
    quickSort(arr, lb, r-1);
    quickSort(arr, r+1, ub);
}

int main() {
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    quickSort(v, 0, n-1);
    cout<<"Output : \n";
    for(int i=0; i<n; i++) {
        cout<<v[i]<<" ";
    }
}
